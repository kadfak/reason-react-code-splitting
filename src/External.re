[@bs.val] external import: string => Js.Promise.t('a) = "import";

module React = {
  [@bs.module "react"]
  external createElement:
    (React.component(Js.t('props)), Js.t('props)) => React.element =
    "createElement";
};
