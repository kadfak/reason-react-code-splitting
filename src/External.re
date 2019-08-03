module React = {
  [@bs.splice] [@bs.module "react"]
  external createElementVariadic:
    (React.component(Js.t('props)), Js.t('props), array(React.element)) =>
    React.element =
    "createElement";
};
