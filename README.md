# prosoft-tasks
1.The Descent
задача: Destroy the mountains before your starship collides with one of them. For that, shoot the highest mountain on your path.
решение:
добавил в исходный код 2 переменные. MAX для записи максимальной высоты горы и target для записи индекса горы. внутри цикла for, где идет обработка высоты горы добавил сравнение текущей высоты с MAX. если mountain_h>MAX, то target присваивается i (запоминаем номер самой высокой горы на данный момент:
if(mountain_h>MAX){
  MAX = mountain_h;
  target = i;
}
далее после проверки всех гор и выявления самой высокой по ней ведется огонь: cout << target << endl;
