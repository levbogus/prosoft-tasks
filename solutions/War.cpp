#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int cardvalue(const string& card){ //нам не нужны масти, необходимо достать только значение
    string value = card.substr(0,card.size()-1);//последний символ - масть, не берем его
    if(value=="J") return 11;
    if(value=="Q") return 12;
    if(value=="K") return 13;
    if(value=="A") return 14;
    else return stoi(value); //возвращаем номинал в виде целого числа из строки
}

int main()
{
    int n; // the number of cards for player 1
    cin >> n; cin.ignore();
    queue<string> deck1, deck2; //создаем 2 колоды, они будут работать так: кладем вниз, берем сверху
    for (int i = 0; i < n; i++) {
        string cardp_1; // the n cards of player 1
        cin >> cardp_1; cin.ignore();
        deck1.push(cardp_1); //кладем карту вниз колоды 1
    }
    int m; // the number of cards for player 2
    cin >> m; cin.ignore();
    for (int i = 0; i < m; i++) {
        string cardp_2; // the m cards of player 2
        cin >> cardp_2; cin.ignore();
        deck2.push(cardp_2); //кладем карту вниз колоды 2
    }
    int rounds=0;
    while(!deck1.empty()&&!deck2.empty()){ //играем пока не опустеет одна из колод
        vector<string> play1{deck1.front()}; //выкладываем верхнюю карту на стол из колоды
        deck1.pop();//удаляем верхнюю карту из колоды
        vector<string> play2{deck2.front()};
        deck2.pop();
        
        bool war = 1;
        while(war){
            int val1 = cardvalue(play1.back()); //конвертируем карту в ее номинал 
            int val2 = cardvalue(play2.back());
            if(val1==val2){
                if(deck1.size()<=3||deck2.size()<=3) {
                    cout <<"PAT"<<endl; 
                    return 0; //в случае пата необходимо закончить игру
                }
                for(int i=0;i<4;i++){
                    play1.push_back(deck1.front()); deck1.pop(); //кладем еще по 3 карты в закрытую и в открытую для каждого игрока
                    play2.push_back(deck2.front()); deck2.pop();
                }               
            }else{
                if(val1>val2){ //выигрыш первого игрока
                    for(string x:play1)deck1.push(x); //кладем в колоду карты со стола. сначала карты 1 игрока, потом 2
                    for(string x:play2)deck1.push(x);                                           
                }else{
                    for(string x:play1)deck2.push(x);                    
                    for(string x:play2)deck2.push(x);
                }   
                play1.clear(); play2.clear();
                war=0;           
            }
        }
        rounds++;
    }
    //если колода 1 пуста - значит победил игрок 2, если она не пуста, то значит пуса 2 и тогда побеждает 1 игрок
    cout << (deck1.empty() ? 2 : 1) <<" "<< rounds << endl; 
}
