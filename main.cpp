#include <iostream>

using namespace std;

//calculate BMI
double calcualteBMI(double height, double weight, double BMI){
    BMI = weight / (height * height);
    return BMI;
}//end calculateBMI

//convert height in inches to meters

double convertHeight(double height){
    //1 inch = 0.0254 meters
    height = height * 0.0254;
    return height;
}//end convertHeight

//convert weight in lb to kg
double convertWeight(double weight){
    //1 pound = 0.453592 kilograms
    weight = weight * 0.453592;
    return weight;
}//end convertWeight

//get weight from the user
double getWeight(double weight){

    bool isKilogram = true;
    cout<<"Do you know your weight in kilograms? (input 0 for no, 1 for yes)"<<endl;
    cin>>isKilogram;
    if(isKilogram){
        cout<<"Enter your weight in kilograms"<<endl;
        cin>>weight;
    }
    else{
        cout<<"Enter your weight in pounds"<<endl;
        cin>>weight;
        weight = convertWeight(weight);
    }
    return weight;
}//end getWeight

//get height from the user
double getHeight(double height){

    bool isMeters = true;
    cout<<"Do you know your height in meters? (input 0 for no, 1 for yes)"<<endl;
    cin>>isMeters;
    if(isMeters){
        cout<<"Enter your height in meters"<<endl;
        cin>>height;
    }
    else{
        cout<<"Enter your height in inches"<<endl;
        cin>>height;
        height = convertHeight(height);
    }
    return height;
}//end getHeight

//calculate weight classification
int calculateWeightClasification(double BMI){
    //normal weight
    if( (BMI < 24.9) && (BMI >= 18.5) )  {
        return 1;
    }
    //overweight
    else if( ( BMI < 29.9) && (BMI >= 25.0) ){
        return 2;
    }
    //obese class 1
    else if( ( BMI < 34.9) && (BMI >= 30.0) ){
        return 3;
    }
    //underweight
    else if(BMI < 18.5){
        return 0;
    }
    //obese class 2
    else if( (BMI < 39.9) && (BMI >= 35.0) ){
        return 4;
    }
    //obese class 3
    else{
        return 5;
    }
}//end calculateWeightClasification

//print result to user
void printResult(double BMI,int classification){
    //BMI
    cout<<"Your BMI is: "<<BMI;

    //weight classification
    switch (classification){
        case 0 : cout<<" that is considered Underweight"<<endl;
            break;
        case 1 : cout<<" that is considered Normal Weight"<<endl;
            break;
        case 2 : cout<<" that is considered Overweight"<<endl;
            break;
        case 3 : cout<<" that is considered Obese Class I"<<endl;
            break;
        case 4 : cout<<" that is considered Obese Class II"<<endl;
            break;
        case 5 : cout<<" that is considered Obese Class III"<<endl;
            break;
    }//end switch
}//end printResult

int main()
{
    double weight = 0, height = 0, BMI = 0;
    int classification = 1;

    //get information from the user

        //get weight
        weight = getWeight(weight);

        //get height
        height = getHeight(height);

    //calculate BMI
    cout<<BMI<<endl;
    BMI = calcualteBMI(height, weight, BMI);
    cout<<BMI<<endl;

    //calculate weight classification
    cout<<classification<<endl;
    classification = calculateWeightClasification(BMI);
    cout<<classification<<endl;
    //report BMI
    printResult(BMI, classification);

    return 0;
}//end main
