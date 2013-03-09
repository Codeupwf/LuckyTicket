#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <iomanip>

using namespace std;
bool isNum(char* value)
{
    int i = 0;
    while(value[i] != '\0')
    {
        int j = *value - '0';
        if((j < 9) && (j >= 0))
        {
            i++;
        }
        else
        {
            cout<<"Error input, not numbers !"<< endl;
            return false;
        }
    }
    return true;
}

//init Random seed
void initRandom()
{
	srand(time(NULL));
}
int getRed()
{
    int iResult = random()%33 + 1;
    return iResult;
}

int getBlue()
{
    int iResult = random()%16 + 1;
    return iResult;
}

int main(int argc,char* argv[])
{
    //output result number
    int iOutNumber;
    //if there is no input arg, create 5 luck numbers as default output
    if(argc < 2)
    {
        iOutNumber = 5;
    }
    if(argc >=2)
    {
        //judge input whether vaild or not
        if(!isNum(argv[1]))
        {
            cout<<"invaild input, create 5 luck numbers as default!"<<endl;
            iOutNumber = 5;
        }
        else
        {
            iOutNumber = atoi(argv[1]);
        }
    }

	//init Random seed
	initRandom();	
    //outer loop
    for(int i = 0; i < iOutNumber; i++)
    {
		//get red balls
		int iRedBalls[34] = {0};
        for(int j = 0; j < 6; j++)
        {
			int iRedBall;
			while(true)
			{
				iRedBall = getRed();
				if(iRedBalls[iRedBall] == 0)
				{
					iRedBalls[iRedBall] = 1;
					break;
				}
			}
            cout << setw(2) << setfill('0') << iRedBall;
            if(j != 6-1)
            {
                cout << " ";
            }
        }

        cout << ":";

		//get blue balls
        cout << setw(2) << setfill('0') << getBlue() << endl;
    }

    return 0;

}
