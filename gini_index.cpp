#include <iostream>
#include <numeric>
#include <cmath>
using namespace std;
double Info_D_Calc(double *labels, int classes)
{
    double sum = 0;
    double Info_D = 0;
    sum = accumulate(labels, labels + classes, sum);
    for (int i = 0; i < classes; i++)
    {
        Info_D += (labels[i] / sum) * (labels[i] / sum);
    }
    return (1 - Info_D);
}
int main()
{
    int classes = 2;
    double Info_D = 0;
    double Info_DA = 0;
    double temp = 0;
    double labels[classes] = {5, 9};
    double sum = 0;
    sum = accumulate(labels, labels + classes, sum);
    Info_D = Info_D_Calc(labels, classes);
    std::cout << "Info_D:" << Info_D;
    int sub_classes = 3;
    double Info_D_2D[sub_classes][classes] = {{2, 2}, {4, 2}, {3, 1}};
    for (int i = 0; i <= sub_classes; i++)
    {
        double a = Info_D_2D[i][0] + Info_D_2D[i][1];
        temp = Info_D_Calc(Info_D_2D[i], classes);
        Info_DA = Info_DA + ((a / sum) * temp);
    }
    std::cout << "\nClass 1:" << Info_DA;
    return 0;
}