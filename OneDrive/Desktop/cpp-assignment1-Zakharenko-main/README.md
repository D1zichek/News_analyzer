# Завдання №1 - Імплементувати сінгелтон

## Завдання
    Необхіжно реалізувати патерн програмування сінгелтон. 
    Також треба реалізувати методи класів UserConfig та SystemConfig.
    У методі fill_data необхідно викликати ініціалюзавти інстатнси класів UserConfig та SystemConfig.
    Також заповнити данні згідно з завданням.

    Необхідно для кожної з конфігурацій додати три призвіща:
    1. Попередню людину перед собою людину в списку (Якщо ви перший в списку - то першим йде остання людина зі списку)
    2. Себе
    3. Наступну після себе людину в списку (Якщо ви останній в списку - то останнім йде перша людина зі списку)

    Для UserConfig треба додати призвище та групу
    Для SystemConfig треба додати призвище та систему зі списку нижче

## Необхідно імплементувати:
    - src/user_config.cpp - add_user, show
    - src/system_config.cpp - add_system, show
    - src/fill.cpp - fill_data
    - src/singleton.hpp - getInstance

## Заборонено змінювати:
    - .github/workflows/students_check.yaml
    - src/main.cpp

## Приклад виводу програми

    User configs:
    1. Arsen'yev - Z-31
    1. Burba - Z-31
    1. Bykanov - Z-31
    System configs:
    1. Arsen'yev - Linux
    1. Burba - Windows
    1. Bykanov - MacOS

## Розподілення операційних систем
### З-31
    Арсеньєв - Linux
    Биканов - MacOS
    Бурба - Windows
    Бурлаченко - Linux
    Дворник - MacOS
    Друженко - Linux
    Жуковська - Windows
    Захаренко - Linux
    Калініченко - MacOS
    Лавров - Linux
    Марченко - Windows
    Меркова - Windows
    Назаренко - Windows
    Паламарчук - Windows
    Савін - Windows
    Трубчанінов - Linux
    Черкасов - Windows
    Чумак - MacOS
    Швець - MacOS

### З-32
    Акімов - MacOS
    Альтерович - MacOS
    Буй - Linux
    Вишневський - MacOS
    Генчева - Linux
    Гордієнко - MacOS
    Грабовенко - Linux
    Замятін - Windows
    Карагодіна - MacOS
    Карпенко - Windows
    Кузьменко - MacOS
    Кульомін - Linux
    Левенець - Windows
    Макаренко - Windows
    Наконечний - Linux
    Поворознюк - MacOS
    Развалінов - Windows
    Рєпін - Windows
    Тонкова - MacOS
    Чабан - Linux
    Шукайло - Windows
    Шумко - Windows

## Очікуване написання призвищ
### З-31
    Арсеньєв - Arsen'yev
    Биканов - Bykanov
    Бурба - Burba
    Бурлаченко - Burlachenko
    Дворник - Dvornyk
    Друженко - Druzhenko
    Жуковська - Zhukovs'ka
    Захаренко - Zakharenko
    Калініченко - Kalinichenko
    Лавров - Lavrov
    Марченко - Marchenko
    Меркова - Merkova
    Назаренко - Nazarenko
    Паламарчук - Palamarchuk
    Савін - Savin
    Трубчанінов - Trubchaninov
    Черкасов - Cherkasov
    Чумак - Chumak
    Швець - Shvets'

### З-32
    Акімов - Akimov
    Альтерович - Al'terovych
    Буй - Buj
    Вишневський - Vyshnevs'kyj
    Генчева - Hencheva
    Гордієнко - Hordiyenko
    Грабовенко - Hrabovenko
    Замятін - Zamjatin
    Карагодіна - Karahodina
    Карпенко - Karpenko
    Кузьменко - Kuz'menko
    Кульомін - Kul'omin
    Левенець - Levenets'
    Макаренко - Makarenko
    Наконечний - Nakonechnyj
    Поворознюк - Povoroznjuk
    Развалінов - Razvalinov
    Рєпін - Ryepin
    Тонкова - Tonkova
    Чабан - Chaban
    Шукайло - Shukajlo
    Шумко - Shumko
