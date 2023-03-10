# A. Закраска прямой
|  |  |
|--|--|
|Ограничение времени|3 секунды|
|Ограничение памяти|64Mb|
|Ввод|стандартный ввод или input.txt|
|Вывод|стандартный вывод или output.txt|

На числовой прямой окрасили N отрезков. Известны координаты левого и правого концов каждого отрезка (Li и Ri). Найти длину окрашенной части числовой прямой.

## Формат ввода
В первой строке находится число N, в следующих N строках - пары L<sub>i</sub> и R<sub>i</sub>. L<sub>i</sub> и R<sub>i</sub> - целые, -10<sup>9</sup> ≤ L<sub>i</sub> ≤ R<sub>i</sub> ≤ 10<sup>9</sup>, 1 ≤ N ≤ 15 000
## Формат вывода
Вывести одно число - длину окрашенной части прямой.


# B. Таможня
|  |  |
|--|--|
|Ограничение времени|3 секунды|
|Ограничение памяти|64Mb|
|Ввод|стандартный ввод или input.txt|
|Вывод|стандартный вывод или output.txt|

Идёт 2163 год. Мишу, который работает в отделении таможни при космодроме города Нью-Питер, вызвал в кабинет шеф.

Как оказалось, недавно Министерство Налогов и Сборов выделило отделению определённую сумму денег на установку новых аппаратов для автоматического досмотра грузов. Естественно, средства были выделены с таким расчётом, чтобы грузы теперь находились на таможне ровно столько времени, сколько требуется непосредственно на их досмотр.

В руках шефа каким-то образом оказались сведения о надвигающейся ревизии – список из N грузов, которые будут контролироваться Министерством. Для каждого груза известны время его прибытия, отсчитываемое с некоторого момента, хранимого в большом секрете, и время, требуемое аппарату для обработки этого груза. Шеф дал Мише задание по этим данным определить, какое минимальное количество аппаратов необходимо заказать на заводе, чтобы все грузы Министерства начинали досматриваться сразу после прибытия. Необходимо учесть, что конструкция тех аппаратов, которые было решено установить, не позволяет обрабатывать два груза одновременно на одном аппарате. Напишите программу, которая поможет Мише справиться с его задачей.

## Формат ввода
На первой строке входного файла задано число N (0 ≤ N ≤ 50 000). На следующих N строках находится по 2 целых положительных числа Ti и Li – время прибытия соответствующего груза и время, требуемое для его обработки (1 ≤ T<sub>i</sub> ≤ 10<sup>6</sup>, 1 ≤ L<sub>i</sub> ≤ 10<sup>6</sup>).

## Формат вывода
В выходной файл выведите одно число – наименьшее количество аппаратов, которое нужно установить, чтобы не вызвать подозрений у Министерства.


# C. Минимальное покрытие
|  |  |
|--|--|
|Ограничение времени|3 секунды|
|Ограничение памяти|64Mb|
|Ввод|стандартный ввод или input.txt|
|Вывод|стандартный вывод или output.txt|

На прямой задано некоторое множество отрезков с целочисленными координатами концов [L<sub>i</sub>, R<sub>i</sub>]. Выберите среди данного множества подмножество отрезков, целиком покрывающее отрезок [0, M], (M — натуральное число), содержащее наименьшее число отрезков.

## Формат ввода
В первой строке указана константа M (1 ≤ M ≤ 5000). В каждой последующей строке записана пара чисел L<sub>i</sub> и R<sub>i</sub> (L<sub>i</sub>, R<sub>i</sub> ≤ 50000), задающая координаты левого и правого концов отрезков. Список завершается парой нулей. Общее число отрезков не превышает 100 000.
## Формат вывода
В первой строке выходного файла выведите минимальное число отрезков, необходимое для покрытия отрезка [0; M]. Далее выведите список покрывающего подмножества, упорядоченный по возрастанию координат левых концов отрезков. Список отрезков выводится в том же формате, что и во входe. Завершающие два нуля выводить не нужно. Если покрытие отрезка [0, M] исходным множеством отрезков [L<sub>i</sub>, R<sub>i</sub>] невозможно, то следует вывести единственную фразу “No solution”. 


# D. Наполненность котятами
|  |  |
|--|--|
|Ограничение времени|2 секунды|
|Ограничение памяти|256Mb|
|Ввод|стандартный ввод или input.txt|
|Вывод|стандартный вывод или output.txt|

На прямой в точках a<sub>1</sub>,a<sub>2</sub>,…,a<sub>n</sub> (возможно, совпадающих) сидят n котят. На той же прямой лежат m отрезков [l<sub>1</sub>, r<sub>1</sub>],[l<sub>2</sub>, r<sub>2</sub>],…,[lm, rm]. Нужно для каждого отрезка узнать его наполненность котятами — сколько котят сидит на отрезке.
## Формат ввода
На первой строке n и m (1 ≤ n,m ≤ 10<sup>5</sup>). На второй строке n целых чисел a<sub>i</sub> (0 ≤ a<sub>i</sub> ≤ 10<sup>9</sup>). Следующие m строк содержат пары целых чисел l<sub>i<sub>,r<sub>i<sub> (0 ≤ l<sub>i</sub> ≤ r<sub>i</sub> ≤ 10<sup>9</sup>).
## Формат вывода
Выведите m целых чисел. i-е число — наполненность котятами i-го отрезка.


# E. Полярные прямоугольники
|  |  |
|--|--|
|Ограничение времени|5 секунд|
|Ограничение памяти|64Mb|
|Ввод|стандартный ввод или input.txt|
|Вывод|стандартный вывод или output.txt|

Вася недавно изучил полярную систему координат. А именно, он изучил понятие полярного прямоугольника. Пусть задана стандартная декартова плоскость. Если на ней нарисовать две окружности с центром в начале координат, то область, находящаяся между ними, называется кольцом (на рисунке обозначена синим). Если на ней нарисовать два луча, то область, заметаемая первым лучом при движении ко второму, называется углом (т.е. область между этими двумя лучами, на рисунке обозначена зеленым). Полярным прямоугольником называется пересечение некоторого угла с некоторым кольцом (на рисунке обозначено красным).

Задано несколько полярных прямоугольников. Найдите площадь их пересечения. Помните, что пересечение полярных прямоугольников может состоять из нескольких частей!

## Формат ввода
В первой строке вводится целое число N — количество прямоугольников (1 ≤ N ≤ 100 000). Далее в N строках содержится описание прямоугольников. Каждый прямоугольник описывается четверкой действительных чисел r<sub>1</sub>, r<sub>2</sub>, φ<sub>1</sub>, φ<sub>2</sub>, где r<sub>1</sub>, r<sub>2</sub> обозначают радиусы окружностей, образующих кольцо (r<sub>1</sub> < r<sub>2</sub>), а φ<sub>1</sub>, φ<sub>2</sub> обозначают углы, образованные первым и вторым лучами с осью абсцисс, заданные в радианах. При этом заметается область от первого луча до второго в направлении против часовой стрелки (т.е. возрастания углов), даже в случае, когда φ<sub>1</sub> > φ<sub>2</sub>. Все числа заданы максимум с шестью знаками после десятичной точки. Углы лежат в полуинтервале [0, 2π), а радиусы не превосходят 10<sup>6</sup>. Гарантируется, что φ<sub>1</sub> ≠ φ<sub>2</sub>.
## Формат вывода
Выведите единственное число — площадь искомого пересечения. Ответ будет считаться правильным, если его абсолютная или относительная погрешность не будет превышать 10<sup>-6</sup>. 