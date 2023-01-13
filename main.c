#include <stdio.h>
int c1[7] = {1, 1, 2, 2 ,3, 4, 5};
int c2[7] = {1, 3, 4, 2, 1, 6, 7};
int turn[10];
int loc = 0;
int map1[10] = {0};
int map2[10] = {0};//map2[i]存放i在2中出现的次数，相当于映射
int compareTo(int n1, int n2)
{
    if(map1[n1] > map1[n2]) return -1;
    else if(map1[n1] < map1[n2]) return 1;
    else
    {
        if(map2[n1] == map2[n2]) return n1 - n2;
        else return map2[n2] - map2[n1];
    }
}
void quickSort(int *array, int left, int right)//排序
{
    if(left >= right) return ;
    int i = left, j = right, current = 1;
    int num = array[left];
    while(i != j)
    {
        if(current)
        {
            while(i != j && compareTo(array[j], num) >= 0) j--;
            if(i != j)
            {
                array[i] = array[j];
            }
            current ^= 1;
        }
        else
        {
            while(i != j && compareTo(array[i], num) <= 0) i++;
            if(i != j)
            {
                array[j] = array[i];
            }
            current ^= 1;
        }
    }
    array[i] = num;
    quickSort(array, left, i - 1);
    quickSort(array, i + 1, right);
}
void printCow()
{
    for(int i = 0; i < 7; i++)
    {
        printf("%d %d\n", c1[i], c2[i]);
    }
}
int main() {
    for(int i = 0; i < 7; i++)
    {
        if(map1[c1[i]] == 0)
        {
            turn[loc++] = c1[i];
        }
        map1[c1[i]]++;
    }
    for(int i = 0; i < 7; i++)
    {
        if(map1[c2[i]] == 0 && map2[c2[i]] == 0)
        {
            turn[loc++] = c2[i];
        }
        map2[c2[i]]++;
    }//记录出现的数字，去重
    quickSort(turn, 0, loc - 1);//排序
    for(int i = 0; i < loc; i++)
    {
        for(int j = 0; j < 7; j++)
        {
            if(c1[j] == turn[i]) c1[j] += 1000;
            if(c2[j] == turn[i]) c2[j] += 1000;
        }
        printCow();
        printf("\n\n");
    }
    return 0;
}
