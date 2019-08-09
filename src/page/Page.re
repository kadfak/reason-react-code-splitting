type t =
  | Home
  | Services
  | Contact
  | NotFound;

type active = option((t, React.element));

let fromPath = path =>
  switch (path) {
  | [] => Home
  | ["services"] => Services
  | ["contact"] => Contact
  | _ => NotFound
  };

let load = (setPage, page) =>
  Js.Promise.(
    (
      switch (page) {
      | Home =>
        External.import("./HomePage.bs.js")
        |> then_(component =>
             resolve(
               External.React.createElement(
                 component##make,
                 HomePage.makeProps(~text="Home", ()),
               ),
             )
           )
      | Services =>
        External.import("./ServicesPage.bs.js")
        |> then_(component =>
             resolve(
               External.React.createElement(
                 component##make,
                 ServicesPage.makeProps(),
               ),
             )
           )
      | Contact =>
        External.import("./ContactPage.bs.js")
        |> then_(component =>
             resolve(
               External.React.createElement(
                 component##make,
                 ContactPage.makeProps(),
               ),
             )
           )
      | NotFound =>
        External.import("./NotFoundPage.bs.js")
        |> then_(component =>
             resolve(
               External.React.createElement(
                 component##make,
                 NotFoundPage.makeProps(),
               ),
             )
           )
      }
    )
    |> then_(element => {
         setPage(page, element);
         resolve();
       })
    |> ignore
  );
