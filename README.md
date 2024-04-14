Команда для компиляции через gcc:

gcc laba.c ./utility/polynomial.c ./utility/typeInfo.c ./types/integer.c ./types/real.c ./types/complex.c ./tests/complex_tests.c ./tests/real_tests.c ./tests/integer_tests.c ./tests/polynomial_tests.c -o laba.exe



Изменения с предыдущей сдачи:
1. Исправлены проблемы с модульностью
2. Исправлен нейминг (функции теперь camelCase. Для тестов отдельная конвенция через нижнее подчеркивание, так можно делать?)
3. Устранены утечки памяти (Вопрос: нормально ли, что появляется столько free()? Лучше ли реализовывать через передачу
адреса, в который нужно записать результат, чем через постоянное выделение памяти? )
4. Добавлен TypeInfo ( насколько я понял, нужно было реализовать синглтон )
5. Добавлены тесты
