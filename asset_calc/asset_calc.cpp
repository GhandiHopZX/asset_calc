// asset_calc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

// globals
struct item {
    string name = "";
    int value = 0;
};

//stubburs

int AV(item asset, int Amount, int LOP, int LOR, int CC); // value out
int EF(item asset, int claim, int amount); // percentage out 
int SLE(int AV, int EF); // single value out
int ARO(int incidents); // Number of incidents
int ALE(int, int); // SLE X ARO = ALE
void menu(); 
void OutText(string, int);
void OutVal(int val);

int main()
{ 
    // eternal methods
    menu();
    
    return 0;
}


int AV(item asset, int Amount, int LOP, int LOR, int CC)
{
    int* meil = new int;
    *meil = asset.value;
    int &melr = *meil;
    int melcpy = melr; // this value doesn't change only when the method is used again
    delete meil;

    return melcpy;
}

int EF(item asset, int claim, int amount)
{
    int* meil = new int;
    *meil = (asset.value * claim) / amount;
    int& melr = *meil;
    int melcpy = melr;
    delete meil;

    return melcpy;
}

int SLE(int AV, int EF)
{
    return AV * EF;
}

int ARO(int incidents)
{
    return incidents;
}

int ALE(int SLE, int ARO)
{
    return SLE * ARO;
}

void menu()
{
    item* newAsset = new item;
    int& value = newAsset->value;
    int* amount = new int;
    string& nameA = newAsset->name;
    item& newAssetR = *newAsset;
    

    int me; // menu choices
    //string* aname = new string;
    int* claim = new int;
    int* incidents = new int;
    int* iALE = new int;
    int* iARO = new int;
    int* iSLE = new int;
    int* iEF = new int;
    int* iAV = new int;
    int* iLOR = new int;
    int* iLOP = new int;
    int* iCC = new int;

    //refs
    int& incidentsR = *incidents;
    int& claimR = *claim;
    int& ALER = *iALE;
    int& amountR = *amount;
    int& AROR = *iARO;
    int& SLER = *iSLE;
    int& EFR = *iEF;
    int& AVR = *iAV;
    int& LORR = *iLOR;
    int& LOPR = *iLOP;
    int& CCR = *iCC;
    //string& anameR = *aname;

    // values to input

    OutText("Select your function type... 1 - 5", 1);
    OutText(" 1 AssetValue,\n 2 Exposure Factor,\n 3 Single Lose Expectancy,\n 4 Annualized Loss Expectancy,\n 5 Annualized Rate of Occurance,\n 6 Quit,\n 7 or greater Clear All", 1);
    cin >> me;


    switch (me)
    {
    case 1:
        OutText("Asset Value", 1);
        OutText("Name of asset?", 1);
        cin >> nameA;
        OutText("value of asset?", 1);
        cin >> value;
        OutText("Amount of assets?", 1);
        cin >> *amount;
        OutText("(Loss of Productivity) LOP of asset?", 1);
        cin >> *iLOP;
        OutText("(Loss of Reputation) LOR of asset?", 1);
        cin >> *iLOR;
        OutText("(Customer Confidence) CC of asset?", 1);
        cin >> *iCC;

        // calculate
        // since this is just a basic prog for now this will only spit out one int no real calculations yet
        OutVal(AV(newAssetR, amountR, LOPR, LORR, CCR));
        menu();
        break;

    case 2:
        OutText("Exposure Factor", 1);
        
        OutText("value of asset?", 1);
        cin >> value;
        OutText("name of asset?", 1);
        cin >> nameA;
        OutText("amount of claims of this asset?", 1);
        cin >> *claim;
        OutText("Amount of assets?", 1);
        cin >> *amount;

        OutVal(EF(newAssetR, claimR, amountR));
        menu();
        break;

    case 3:
        OutText("Single Loss Expectancy", 1);
        OutText("(Asset Value) AV of asset?", 1);
        cin >> *iAV;
        OutText("(Exposure Factor) EF of asset?", 1);
        cin >> *iEF;

        OutVal(SLE(AVR, EFR));
        menu();
        break;

    case 4:
        OutText("Annualized Loss Expectancy", 1);
        OutText("(Single Loss Expectancy) SLE of asset?", 1);
        cin >> *iSLE;
        OutText("(Annualized Rate of Occurance) ARO of asset?", 1);
        cin >> *iARO;

        OutVal(ALE(SLER, AROR));
        menu();
        break;

    case 5:
        OutText("Annualized Rate of Occurance", 1);
        OutText("Number of incidents?", 1);
        cin >> *incidents;

        OutVal(ARO(incidentsR));
        menu();
        break;

    case 6:
        OutText("Quit", 1);
        EXIT_SUCCESS;
        break;

    default:
        OutText("CLEARING ALL VALUES", 1);
        delete newAsset;
        delete claim;
        delete incidents;
        delete iALE;
        delete iARO;
        delete iLOR;
        delete iLOP;
        delete iCC;
        delete iSLE;
        delete iEF;
        delete iAV;
        system("CLS");
        menu();
        break;
        
    }
}

void OutText(string text, int times)
{
    for (int i = 0; i < times; i++)
    {
        cout << text << endl;
    }
}
void OutVal(int val) {
    cout << val << endl;
}