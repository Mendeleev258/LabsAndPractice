// Задача 5 - пулл потоков

// Для работы необходимо будет реализовать
// потокобезопасный стек, который в приватных полях будет содержать
// std::stack и объект захвата,
// а в паблике будут методы bool empty(), void push(...), bool try_pop();
// последние два метода - потокобезопасные (необходимо заранее запрашивать разрешение).