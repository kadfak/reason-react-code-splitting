[@bs.val] external import: string => Js.Promise.t('a) = "import";

[@bs.module "react"]
external lazy_: (unit => Js.Promise.t('a)) => 'a = "lazy";

let loadPage = moduleName => lazy_(() => import({j|./$moduleName.bs.js|j}));
