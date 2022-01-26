#include<iostream>

using namespace std;

int solution(int N);

int main(){
    int number;

    cout << "Write a number: ";
    cin >> number;

    cout << "Your's the longest binary gap has: " << solution(number) << " zero/s.";
}

int solution(int N)
{
    int binary[32], gapSize[30], i;

    gapSize[0] = 0;
    int j = 0;

    for(i=0; N>0; i++)
    {
        binary[i]=N%2;
        N = N/2;
    }

    while(i != 0)
    {
        i--;
        if(binary[i] == 0)
        {
            while((binary[i] != 1 && i!=0))
            {
                gapSize[j] += 1;
                i--;
                if(i == 0 && binary[i] == 0)
                {
                    gapSize[j] = 0;
                }
            }
            j++;
            gapSize[j] = 0;
        }
        else
        {
            gapSize[j] = 0;
        }
    }

    int theLongest = gapSize[j];

    for(j; j>=0; j--)
    {
        if(gapSize[j] > theLongest)
        {
            theLongest = gapSize[j];
        }
    }

    return theLongest;
}
