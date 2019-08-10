type action =
  | SetPageElement(React.element);

type state = {pageElement: React.element};

let loadPage = (dispatch, url: ReasonReactRouter.url) =>
  Js.Promise.(
    url.path
    |> Page.fromPath
    |> Page.load
    |> then_(element => {
         dispatch(SetPageElement(element));
         resolve();
       })
    |> ignore
  );

[@react.component]
let make = () => {
  let (state, dispatch) =
    React.useReducer(
      (state, action) =>
        switch (action) {
        | SetPageElement(pageElement) => {pageElement: pageElement}
        },
      {pageElement: React.null},
    );

  React.useEffect0(() => {
    open ReasonReactRouter;

    dangerouslyGetInitialUrl() |> loadPage(dispatch);
    let watcherId = watchUrl(url => loadPage(dispatch, url));

    Some(() => unwatchUrl(watcherId));
  });

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
    <div className="page"> {state.pageElement} </div>
  </div>;
};
