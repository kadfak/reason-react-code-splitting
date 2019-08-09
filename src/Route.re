type t =
  | Home
  | Services
  | Contact;

let go = route =>
  ReasonReactRouter.push(
    switch (route) {
    | Home => "/"
    | Services => "/services"
    | Contact => "/contact"
    },
  );
