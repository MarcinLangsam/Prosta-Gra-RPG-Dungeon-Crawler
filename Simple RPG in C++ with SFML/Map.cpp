#include <cmath>
#include "Map.h"

using namespace std;

void Map::small_room()
{
    const int h = 6;
    const int w = 6;

    room_height = h;
    room_width = w;


    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            s_room[i][j] = "#";
        }
    }

    int tresure_roll = rand() % 100;
    if (tresure_roll > 50)
    {   
        int special_object = rand() % 100;
        if (special_object < 40) s_room[3][3] = "C";
        if (special_object >= 40 && special_object < 70) s_room[2][2] = "F";
        if (special_object >= 70 && special_object < 90) s_room[2][2] = "S";
        if (special_object >= 90 && special_object <= 100) s_room[2][2] = "T";
        
    }
    else s_room[2][2] = "W";

    if (first == true) s_room[2][2] = "P";

}

void Map::medium_room()
{
    const int h = 8;
    const int w = 8;
    bool done = false;

    room_height = h;
    room_width = w;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            m_room[i][j] = "#";
        }
    }
    
    int point_x = rand() % 5 + 2;
    int point_y = rand() % 5 + 2;

    int special_object = rand() % 100;
    if (special_object < 40) m_room[point_x][point_y] = "C";
    if (special_object >= 40 && special_object < 70) m_room[point_x][point_y] = "F";
    if (special_object >= 70 && special_object < 90) m_room[point_x][point_y] = "S";
    if (special_object >= 90 && special_object <= 100) m_room[point_x][point_y] = "T";

    m_room[point_x+1][point_y] = ",";
    m_room[point_x-1][point_y] = ",";
    m_room[point_x][point_y+1] = ",";
    m_room[point_x][point_y-1] = ",";
    m_room[point_x+1][point_y+1] = ",";
    m_room[point_x+1][point_y-1] = ",";
    m_room[point_x-1][point_y+1] = ",";
    m_room[point_x-1][point_y-1] = ",";


    while (done == false)
    {
        int point_x = rand() % 5 + 2;
        int point_y = rand() % 5 + 2;

        if (m_room[point_x][point_y] != "," && m_room[point_x][point_y] != "C" && m_room[point_x][point_y] != "F" && m_room[point_x][point_y] != "S" && m_room[point_x][point_y] != "T")
        {
            int special_object = rand() % 100;
            if (special_object < 40) m_room[point_x][point_y] = "C";
            if (special_object >= 40 && special_object < 70) m_room[point_x][point_y] = "F";
            if (special_object >= 70 && special_object < 90) m_room[point_x][point_y] = "S";
            if (special_object >= 90 && special_object <= 100) m_room[point_x][point_y] = "T";

            m_room[point_x + 1][point_y] = ",";
            m_room[point_x - 1][point_y] = ",";
            m_room[point_x][point_y + 1] = ",";
            m_room[point_x][point_y - 1] = ",";
            m_room[point_x + 1][point_y + 1] = ",";
            m_room[point_x + 1][point_y - 1] = ",";
            m_room[point_x - 1][point_y + 1] = ",";
            m_room[point_x - 1][point_y - 1] = ",";

            int rool_for_enemy = rand() % 100;
            if(rool_for_enemy > 40) m_room[point_x + 1][point_y + 1] = "W";

            done = true;
        }
    }
    done = false;
    while (done == false)
    {
        int point_x = rand() % 5 + 2;
        int point_y = rand() % 5 + 2;

        if (m_room[point_x][point_y] != "," && m_room[point_x][point_y] != "C" && m_room[point_x][point_y] != "F" && m_room[point_x][point_y] != "S" && m_room[point_x][point_y] != "T")
        {
            m_room[point_x][point_y] = "W";
            done = true;
        }
    }
}

void Map::big_room()
{
    
    const int h = 12;
    const int w = 12;
    bool done = false;


    room_height = h;
    room_width = w;


    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            b_room[i][j] = "#";
        }
    }

    int divide_x = rand() % 6 + 3;
    int divide_y = rand() % 6 + 3;

    for (int i = 0; i < h; i++)
    {
        b_room[divide_x][i] = ".";
    }

    for (int i = 0; i < w; i++)
    {
        b_room[i][divide_y] = ".";
    }

    b_room[divide_x + 1][divide_y] = "#";
    b_room[divide_x + 2][divide_y] = "#";
    b_room[divide_x - 1][divide_y] = "#";
    b_room[divide_x - 2][divide_y] = "#";
    b_room[divide_x][divide_y + 1] = "#";
    b_room[divide_x][divide_y + 2] = "#";
    b_room[divide_x][divide_y - 1] = "#";
    b_room[divide_x][divide_y - 2] = "#";


    int point_x = rand() % 5 + 2;
    int point_y = rand() % 5 + 2;

    int special_object = rand() % 100;
    if (special_object < 40) b_room[point_x][point_y] = "C";
    if (special_object >= 40 && special_object < 70) b_room[point_x][point_y] = "F";
    if (special_object >= 70 && special_object < 90) b_room[point_x][point_y] = "S";
    if (special_object >= 90 && special_object <= 100) b_room[point_x][point_y] = "T";

    b_room[point_x + 1][point_y] = ",";
    b_room[point_x - 1][point_y] = ",";
    b_room[point_x][point_y + 1] = ",";
    b_room[point_x][point_y - 1] = ",";
    b_room[point_x + 1][point_y + 1] = ",";
    b_room[point_x + 1][point_y - 1] = ",";
    b_room[point_x - 1][point_y + 1] = ",";
    b_room[point_x - 1][point_y - 1] = ",";
    
    for(int i=0;i<2;i++)
    {
        int point_x = rand() % 5 + 2;
        int point_y = rand() % 5 + 2;

        if (b_room[point_x][point_y] != "," && b_room[point_x][point_y] != "C" && b_room[point_x][point_y] != "F" && b_room[point_x][point_y] != "S" && b_room[point_x][point_y] != "T")
        {
            int special_object = rand() % 100;
            if (special_object < 40) b_room[point_x][point_y] = "C";
            if (special_object >= 40 && special_object < 70) b_room[point_x][point_y] = "F";
            if (special_object >= 70 && special_object < 90) b_room[point_x][point_y] = "S";
            if (special_object >= 90 && special_object <= 100) b_room[point_x][point_y] = "T";

            b_room[point_x + 1][point_y] = ",";
            b_room[point_x - 1][point_y] = ",";
            b_room[point_x][point_y + 1] = ",";
            b_room[point_x][point_y - 1] = ",";
            b_room[point_x + 1][point_y + 1] = ",";
            b_room[point_x + 1][point_y - 1] = ",";
            b_room[point_x - 1][point_y + 1] = ",";
            b_room[point_x - 1][point_y - 1] = ",";

            int rool_for_enemy = rand() % 100;
            if (rool_for_enemy > 40) b_room[point_x + 1][point_y + 1] = "W";
        }
    }

    
    for (int i = 0; i < 2; i++)
    {
        int point_x = rand() % 5 + 2;
        int point_y = rand() % 5 + 2;

        if (b_room[point_x][point_y] != "," && b_room[point_x][point_y] != "C" && b_room[point_x][point_y] != "F" && b_room[point_x][point_y] != "S" && b_room[point_x][point_y] != "T")
        {
            b_room[point_x][point_y] = "W";
            
        }
    }
}

void Map::corridor()
{
    const int h = 10;
    const int w = 5;

    room_height = h;
    room_width = w;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            c_room[i][j] = "#";
        }
    }

    int divide_x = rand() % 6 + 3;

    for (int i = 0; i < w; i++)
    {
        c_room[divide_x][i] = ".";
    }

    c_room[divide_x][2] = "#";
    c_room[divide_x][3] = "#";

    int rool_for_enemy = rand() % 100;
    if (rool_for_enemy > 20) c_room[divide_x][2] = "W";

    int rool_for_tresure = rand() % 100;
    if (rool_for_tresure > 50)
    {
        if (divide_x < 6) c_room[divide_x + 2][4] = "C";
        else c_room[divide_x - 2][4] = "C";
    }
}

void Map::generator()
{
    const int h = height;
    const int w = width;

    srand(time(NULL));


    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            map[i][j] = ".";
        }
    }

    first = true;
    small_room(); //sztywy pokoj startowy dla gracza
    first = false;
    x = 22;
    y = 13;

    for (int i = x; i < x + room_height; i++)
    {

        for (int j = y; j < y + room_width; j++)
        {

            map[i][j] = s_room[count_x][count_y];
            count_y++;
        }
        count_x++;
        count_y = 0;
    }

    go_up();
    bool stop = true;
    while (stop == true)
    {
        stop = fill_map();
    }
    map[x + 11][y + 1] = "O"; // wyjscie

    //poka¿ w konsoli
    cout << "\n\n\n";
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    first = false;
}

bool Map::go_up()
{
    count_x = 0;
    count_y = 0;
    
    
    string room_type = roll_room_type();
    x -= 14;
    
    if (check_border(room_height) == false)
    {
     


        for (int i = x; i < x + room_height; i++)
        {

            for (int j = y; j < y + room_width; j++)
            {

                if (room_type == "s") map[i][j] = s_room[count_x][count_y];
                if (room_type == "m") map[i][j] = m_room[count_x][count_y];
                if (room_type == "b") map[i][j] = b_room[count_x][count_y];
                if (room_type == "c") map[i][j] = c_room[count_x][count_y];
                count_y++;
            }
            count_x++;
            count_y = 0;
        }

        for (int i = x; i < x + 14; i++)
        {

            for (int j = y; j < y + room_width; j++)
            {

                if (map[i][j] == ".") map[i][j] = "#";
            }
        }


        middle_x = x;
        middle_y = y;
        return true;

    }
    else
    {
        x += room_height;
        return false;
    }

}

bool Map::go_left()
{
    count_x = 0;
    count_y = 0;
    

    string room_type = roll_room_type();
    y -= room_width;

    if (check_border(room_height) == false)
    {
        for (int i = x; i < x + room_height; i++)
        {

            for (int j = y; j < y + room_width; j++)
            {

                if (room_type == "s") map[i][j] = s_room[count_x][count_y];
                if (room_type == "m") map[i][j] = m_room[count_x][count_y];
                if (room_type == "b") map[i][j] = b_room[count_x][count_y];
                if (room_type == "c") map[i][j] = c_room[count_x][count_y];
                count_y++;
            }
            count_x++;
            count_y = 0;
        }

        for (int i = x; i < x + room_height; i++)
        {

            for (int j = y; j < y + room_width; j++)
            {

                if (map[i][j] == ".") map[i][j] = "#";
            }
        }

        return true;
    }
    else
    {
        y += room_width;
        return false;
    }
}

bool Map::go_right()
{
    count_x = 0;
    count_y = 0;
    y += room_width;

    string room_type = roll_room_type();

    if (check_border(room_width,room_height) == false) {
        for (int i = x; i < x + room_height; i++)
        {

            for (int j = y; j < y + room_width; j++)
            {

                if (room_type == "s") map[i][j] = s_room[count_x][count_y];
                if (room_type == "m") map[i][j] = m_room[count_x][count_y];
                if (room_type == "b") map[i][j] = b_room[count_x][count_y];
                if (room_type == "c") map[i][j] = c_room[count_x][count_y];
                count_y++;
            }
            count_x++;
            count_y = 0;
        }

        for (int i = x; i < x + room_height; i++)
        {

            for (int j = y; j < y + room_width; j++)
            {

                if (map[i][j] == ".") map[i][j] = "#";
            }
        }

        return true;
    }
    else
    {
        y -= room_width;
        return false;
    }
}

bool Map::check_border(int rh)
{
    if(x<0 || x+rh>=height)
    {
        return true;
    }
    if (y < 0 || y >= width)
    {
        return true;
    }
    return false;
}

bool Map::check_border(int rw, int rh)
{
    if (x < 0 || x+rh >= height)
    {
        return true;
    }
    if (y < 0 || y+rw >= width)
    {
        return true;
    }
    return false;
}

std::string Map::roll_room_type()
{
    
    int r = rand() % 10000;
    if (r < 3000) { small_room(); return "s"; }
    if (r >= 3000 && r <= 5000) { medium_room(); return "m"; }
    if (r >= 5000 && r <= 8500) { big_room(); return "b"; }
    if (r > 8500) { corridor(); return "c"; }
    
}

bool Map::fill_map()
{

    bool left = true;
    bool right = true;
        
    while (left == true)
    {
        if (go_left() == false)
        {
            left = false;
        }
    }

    x = middle_x;
    y = middle_y;

    while (right == true)
    {
        if (go_right() == false)
        {
            right = false;
        }
    }

    x = middle_x;
    y = middle_y;

    if (go_up() == false)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void Map::show()
{
    for(int i=0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}