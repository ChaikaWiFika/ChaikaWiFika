#include <iostream>
using namespace std;

int main(){
int max_time = 0;
int time_count = 0;
int current_time = 0;
int depth_of_tree = 0;
int count_of_commits = 0;
int previous_position = 0;
int small_time = 0;
int big_time = 0;
int temppos = 0;
int left,right = 0;
int i,j,k = 0;//для циклов счётчики
cin >> count_of_commits >> small_time >> big_time; //должно сработать
char commit_list[count_of_commits - 1] = "";
cin >> commit_list;
//не уверен насчёт использования math.h поэтому перестрахуюсь
	if (count_of_commits <= 2)
    {
	if (commit_list[1] == 'B') {time_count = big_time;}
    else {time_count = small_time;}
	}
	else if (count_of_commits <= 4){depth_of_tree = 2;}
	else if (count_of_commits <= 8){depth_of_tree = 3;}
	else if (count_of_commits <= 16){depth_of_tree = 4;}
	else if (count_of_commits <= 32){depth_of_tree = 5;}
	else if (count_of_commits <= 64){depth_of_tree = 6;}
	else if (count_of_commits <= 128){depth_of_tree = 7;}
	else if (count_of_commits <= 256){depth_of_tree = 8;}
	else if (count_of_commits <= 512){depth_of_tree = 9;}
	else if (count_of_commits <= 1024){depth_of_tree = 10;}
	else if (count_of_commits <= 2048){depth_of_tree = 11;}
	else if (count_of_commits <= 4096){depth_of_tree = 12;}
int current_position = count_of_commits / 2;
previous_position = count_of_commits;
//зумеры изобрели логарифмы
k = current_position;

for ( ; i < count_of_commits; ){
	for (; j < depth_of_tree; ){
		temppos = current_position;
    	if (current_position > i) {
        	for (; k < previous_position; ){
            	if (commit_list[k] == 'B'){current_time =+ big_time;
					break;}
				else
				k++;
				current_time =+ small_time;
           	}
    	current_position = current_position/2;
    	}//закрываем if
  	    else {
			for (; k > previous_position; ){
            	if (commit_list[k] == 'B'){current_time =+ big_time;
					break;}
				else
				k--;
				current_time =+ small_time;
            	}
    	current_position = current_position / 2 + current_position;
		}//закрыли else
		j++;
		previous_position = temppos;
		cout << j << endl;
    }
	if (current_time > max_time){max_time = current_time;}
	current_time = 0;
	i++;
}
max_time = max_time + small_time;
cout << max_time << endl;
return 0;
}
