Команда для компиляции через gcc:

gcc polynomials.c ./utility/polynomial.c ./utility/typeInfo.c ./types/real.c ./types/integer.c ./types/complex.c ./tests/integer_tests.c ./tests/polynomial_tests.c ./tests/real_tests.c ./tests/complex_tests.c  -o polynomials.exe


Изменения с предыдущей сдачи:
1. Исправлена большая часть замечаний 
2. Убраны все передачи структуры по значению, но теперь чтобы создать polynomial пользователю нужно сначала динамически выделить под него память. Из-за этого нельзя спрятать реализацию struct polynomial. Также т.к. нет деструкторов, чтобы удалять polynomial вместе с коэффициентами есть функция deletePolynomial(), освобождающая всю память. 
3. В типы добавлены нейтральные элементы  
4. По поводу реализации typeInfo.initialized: при декларации static TypeInfo type_info в функции get<Type>TypeInfo(), в поля этой структуры записываются дефолтные значения, а не мусор, поэтому в int поле попадает 0. Это можно проверить, раскомментировав printf в ./types/integer.c - getIntegerTypeInfo(). При первом создании integer многочлена initialized будет равен 0, при всех последующих - 1. Поэтому это неявный, но рабочий способ (я просто не понял, как это сделать по другому).

