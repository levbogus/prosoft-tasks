# prosoft-tasks
**1.The Descent**  
ссылка на задание:
задача: Destroy the mountains before your starship collides with one of them. For that, shoot the highest mountain on your path.  
решение:  
[The Descent](solutions/The_Descent.cpp)  
добавил в исходный код 2 переменные. MAX для записи максимальной высоты горы и target для записи индекса горы. внутри цикла for, где идет обработка высоты горы добавил сравнение текущей высоты с MAX. если mountain_h>MAX, то target присваивается i (запоминаем номер самой высокой горы на данный момент:  

    if(mountain_h>MAX){  
      MAX = mountain_h;  
      target = i;  
    }  
далее после проверки всех гор и выявления самой высокой по ней ведется огонь: cout << target << endl;  
**2.Power of Thor - Episode 1**  
ссылка на задание: https://www.codingame.com/ide/puzzle/power-of-thor-episode-1
задача: Your program must allow Thor to reach the light of power.  
решение:  
[Power of Thor - Episode 1](solutions/Power_of_Thor_Episode_1.cpp)  
после получения данных об изначальном местоположении объектов ввел новые переменные для отслеживания позиции тора на карте:   

    int thor_x = initial_tx;  
    int thor_y = initial_ty;  
в переменную dir будет записываться направление. определяется относительное положение тора по вертикали:  

    if (thor_y<light_y){  
      dir = "S";  
      thor_y++;  
    } else if (thor_y>light_y){  
       dir = "N";  
       thor_y--;  
    }  
в этом случае если thor_y<light_y, то в dir записывается "S" (движение на юг), а также изменяется thor_y, чтобы в следующий раз сравнивать не с изначальным положением, а с текущим. если же thor_y>light_y, то все происходит аналогично. случай когда thor_y=light_y учтен таким образом, что движение по вертикали не нужно, соответственно и изменять параметры тоже не требуется. с движением по горизонтали аналогично:  

    if (thor_x<light_x){  
       dir += "E";  
       thor_x++;          
    } else if (thor_x>light_x){  
       dir += "W";  
       thor_x--;  
    }  
**3. Temperatures**  
ссылка на задание: https://www.codingame.com/ide/puzzle/temperatures  
задача: Write a program that prints the temperature closest to 0 among input data. If two numbers are equally close to zero, positive integer has to be considered closest to zero (for instance, if the temperatures are -5 and 5, then display 5).  
решение:  
новая переменная answer = 5530 так как максимальная температура в этой задаче 5526. в условии происходит сравнение между абсолютными значениями текущей температуры и answer. если t<answer по модулю, тогда присваиваем answer = t. в случае равенства по модулю, но отличия по знаку, в ответ должно пойти положительное число, это проверяется во втором условии.
  if(abs(t)<abs(answer)||(t+answer==0&&t>=0)) answer = t;  
дополнительная проверка if(n==0) answer=0; нужна для того, чтобы при отсутствии данных на входе, программа возвращала 0
**4.Mars Lander - Episode 1**  
ссылка на задание: https://www.codingame.com/ide/puzzle/mars-lander-episode-1  
задача:The goal for your program is to safely land the "Mars Lander" shuttle, the landing ship which contains the Opportunity rover. Mars Lander is guided by a program, and right now the failure rate for landing on the NASA simulator is unacceptable.  
решение:  
главным условием задачи является приземление КА на поверхность со скоростью меньше 40 м/с. для этого нужно задать условие набора мощности двигателя при пороговом значении, а также выключать двигатели в момент, когда скорость юудет слишком низкой. лополнительным условием является скорость при посадке менее 20 м/с - тогда выводится сообщение Success: kudos! Perfect landing. Opportunity reached Mars safe and sound!, что означает мягкую посадку. для реализации этого случая необходимо начать торможение при 30м/с.   
        if(v_speed<-32&&power<4) power++;  
        else if(v_speed>-10&&power>0) power--;  
**5.Horse-racing Duals**  
ссылка на задание: https://www.codingame.com/ide/puzzle/horse-racing-duals  
задача:Write a program which, using a given number of strengths, identifies the two closest strengths and shows their difference with an integer (≥ 0).  
решение:  
запишем силу каждой лошади в массив и затем отсортируем его. во втором цикле найдем минимальное значение между соседними элементами.  
    sort(horses,horses+n);
    for(int i=1; i<n; i++){  
        if(horses[i]-horses[i-1]<min) min=horses[i]-horses[i-1];  
    }  





  

