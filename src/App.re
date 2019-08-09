type action =
  | SetPage(Page.active);

type state = {page: Page.active};

let setPage = (dispatch, page, element) =>
  dispatch(SetPage(Some((page, element))));

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetPage(page) => {page: page}
        },
      {page: None},
    );

  let url = ReasonReactRouter.useUrl();

  let page = url.path->Page.fromPath;

  let pageElement =
    switch (page, state.page) {
    | (page, Some((activePage, element))) =>
      if (page != activePage) {
        Page.load(setPage(dispatch), page);
      };
      element;
    | (_, None) =>
      Page.load(setPage(dispatch), page);
      React.null;
    };

  <div className="container">
    <div className="menu">
      <div className="menuItem" onClick={_ => Route.go(Home)}>
        "Home"->React.string
      </div>
      <div className="menuItem" onClick={_ => Route.go(Services)}>
        "Services"->React.string
      </div>
      <div className="menuItem" onClick={_ => Route.go(Contact)}>
        "Contact"->React.string
      </div>
    </div>
    <div className="page"> pageElement </div>
  </div>;
};
