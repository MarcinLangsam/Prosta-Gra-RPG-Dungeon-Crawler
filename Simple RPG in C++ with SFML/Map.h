#include <SFML/Graphics.hpp>
#include <iostream>

const int height=33;
const int width=33;

class Map
{
public:
    std::string map[height][width];
    std::string s_room[6][6];
    std::string m_room[8][8];
    std::string b_room[12][12];
    std::string c_room[10][5];
    int room_height = 0;
    int room_width = 0;
    int room_center_up[2] = {0,0};
    int room_center_left[2] = {0,0};
    int room_center_right[2] = {0,0};
    int x=22;
    int y=13;
    bool first = false;
    int count_x = 0;
    int count_y = 0;
    int middle_x = 0;
    int middle_y = 0;
    
    void show();
    void small_room();
    void medium_room();
    void big_room();
    void corridor();
    void generator();
    bool check_border(int rh);
    bool check_border(int rw,int rh);
    bool go_up(); //idzie w gore mapy i tworzy pokuj na srodku 
    bool go_left(); //idzie w lewo i tworzy pokoj
    bool go_right(); //idzie w prawo i tworzy pokoj
    std::string roll_room_type(); //losuje typ pokoju
    bool fill_map(); //kozysta z go_right/left/up, idze w gore dopoki nie skonczy sie przestrzen na pokoje uzupelniajac przestrzen na lewo i prawo 
};