type page =
  | Home
  | Services
  | Contact;

let setPage = page =>
  ReasonReactRouter.push(
    switch (page) {
    | Home => "/"
    | Services => "/services"
    | Contact => "/contact"
    },
  );

[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();

  let page =
    switch (url.path) {
    | [] =>
      React.createElementVariadic(
        Lazy.loadPage("HomePage"),
        HomePage.makeProps(~text="Home", ()),
        [||],
      )
    | ["services"] =>
      React.createElementVariadic(
        Lazy.loadPage("ServicesPage"),
        ServicesPage.makeProps(),
        [||],
      )
    | ["contact"] =>
      React.createElementVariadic(
        Lazy.loadPage("ContactPage"),
        ContactPage.makeProps(),
        [||],
      )
    | _ =>
      React.createElementVariadic(
        Lazy.loadPage("NotFoundPage"),
        NotFoundPage.makeProps(),
        [||],
      )
    };

  <div className="container">
    <div className="menu">
      <div className="menuItem" onClick={_ => setPage(Home)}>
        "Home"->React.string
      </div>
      <div className="menuItem" onClick={_ => setPage(Services)}>
        "Services"->React.string
      </div>
      <div className="menuItem" onClick={_ => setPage(Contact)}>
        "Contact"->React.string
      </div>
    </div>
    <div className="page">
      <React.Suspense fallback=React.null> page </React.Suspense>
    </div>
  </div>;
};
