#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <math.h>
#include <ctype.h>
#include <string.h>
#include <vector>
#include <fstream>
#include <bits/stdc++.h>
using namespace std;


std::pair<std::string,int> sortmin(int allcounts[],std::string upp, std::string lower, std::string dig, std::string special)
{
    std::string min = "";
    std::string all[4] = {upp,lower,dig,special};
    int j = 0;
    for(int i = 0; i<4; i++)
    {
        if(i == 0)
        {
            min = upp;
            j = 0;
        }
        else if(allcounts[i]<= allcounts[j])
        {
            min = all[i];
            j = i;

        }
    }
    return std::make_pair(min,j);
}

std::pair<std::string,int> sortmax(int allcounts[],std::string upp, std::string lower, std::string dig, std::string special)
{
    std::string max = "";
    std::string all[4] = {upp,lower,dig,special};
    int j = 0;
    for(int i = 0; i<4; i++)
    {
        if(i == 0)
        {
            max = upp;
            j = 0;
        }
        else if(allcounts[i]>= allcounts[j])
        {
            max = all[i];
            j = i;
        }
    }
    return std::make_pair(max,j);
}

std::pair<std::string,int> findcat(std::string allstrings[], std::string currstring)
{
    std::string foundcat = "";
    int foundindex = -1;
    for(int i = 0; i<4; i++)
    {
        if(currstring.size() !=0)
        {
            std::size_t pos = allstrings[i].find(currstring[0]) ;
            if(pos != std::string::npos)
            {
                foundcat = allstrings[i];
                foundindex = i;
                break;
            }
        }
    }
    return std::make_pair(foundcat,foundindex);
    
}

//allcounts = changecounts(allcounts, categorymin, categorymax,upper,lower,digit,special); 

void changecounts(int allcounts[],std::string allstrings[], std::string catmin, std::string catmax)
{
    for(int i = 0; i<4; i++)
    {
        if(catmax == allstrings[i])
        {
            allcounts[i] = allcounts[i] - 1;
        }
    }
    for(int i = 0; i<4; i++)
    {
        if(catmin == allstrings[i])
        {
            allcounts[i] = allcounts[i] +1;
        }
    }
    //return allcounts;

}




std::string strengthen(const std::string& password, int& iterat)
{
    std::string upper = "EARIOTNSLCUDPMHGBFYWKVXZJQ";
    std:: string lower = "eariotnslcudpmhgbfywkvxzjq";
    std:: string digit = "0123456789";
    std:: string special = "!?*&^%$#@.";


    std::string allstrings[4] = {upper,lower,digit,special};


    std::string upperpas = "";
    std::string lowerpas = "";
    std::string digitpas = "";
    std::string specialpas = "";


    int uppercount =0;
    int lowercount = 0;
    int digitcount = 0;
    int specialcount = 0;


    std::string strongerpass = password;

    if(iterat == 0)
    {
        cout << "Initial password: " << password << endl;
    }
    
    for(int i = 0; i < password.size(); i++)
    {
        if (upper.find(password[i])>=0 && upper.find(password[i])<26 )
        {
            uppercount++;
            upperpas += password[i];
        }
        else if(lower.find(password[i])>=0 && lower.find(password[i])<26 )
        {
            lowercount++;
            lowerpas += password[i];
        }
        else if(digit.find(password[i])>=0 && digit.find(password[i])<10 )
        {
            digitcount++;
            digitpas += password[i];
        }
        else if(special.find(password[i])>=0 && special.find(password[i])<9 )
        {
            specialcount++;
            specialpas += password[i];
        }
    }

    std::string all[4] = {upperpas,lowerpas,digitpas,specialpas};

    int allcounts[4] = {uppercount, lowercount, digitcount, specialcount};

    for(int i = 0; i<3; i++)
    {
        

        std::pair<std::string, int> resultmost1 = sortmax(allcounts,upperpas,lowerpas,digitpas,specialpas);
        std::string moststr = resultmost1.first;
        int mostindex1 = resultmost1.second;

        
        std::pair<std::string, int> resultmin1 = sortmin(allcounts,upperpas,lowerpas,digitpas,specialpas);
        std::string minstr = resultmin1.first;
        int minindex1 = resultmin1.second;


        if(iterat == 0)
        {
            std::cout <<"counts: upper: "<<upperpas <<" "<< uppercount << " lower: "<<lowerpas<< " " << lowercount <<" digit: "<<digitpas<<" " <<digitcount << " special: "<< specialpas<<" " << specialcount << endl;
            std::cout << "max str: " << moststr << " min str: " << minstr << endl;
        }

        char changeletter;
        if(moststr.size() != 0)
        {
            if(i<moststr.size())
            {
                changeletter = moststr[i];
            }
            else
            {
                changeletter = moststr[0];
            }
            
        }

        char changeletterto;
        std::pair<std::string, int> resultmin = findcat(allstrings, minstr);
        std::string categorymin = resultmin.first;
        int minindex = resultmin.second;

        std::pair<std::string, int> resultmax = findcat(allstrings, moststr);
        std::string categorymax = resultmax.first;
        int maxindex = resultmax.second;

        // std::string categorymin = findcat(allstrings, minstr);
        // std::string categorymax = findcat(allstrings, moststr);
        if(iterat == 0)
        {
            cout << "category min: " << minindex1 << "category max: " << categorymax << endl;
        }

         if(allstrings[minindex1] == upper)
        {
            changeletterto = upper[upper.size()-(i+1)];
            changecounts(allcounts,allstrings, upper, categorymax);
        }
        else if(allstrings[minindex1] == lower)
        {
            changeletterto = lower[lower.size()-(i+1)];
            changecounts(allcounts,allstrings, lower, categorymax);
        }
        else if(allstrings[minindex1] == digit)
        {
            changeletterto = digit[digit.size()-(i+1)];
            changecounts(allcounts,allstrings, digit, categorymax);
        }
        else if(allstrings[minindex1] == special)
        {
            changeletterto = special[special.size()-(i+1)];
            changecounts(allcounts,allstrings, special, categorymax);
        }
        else
        {
            changeletterto = '@';
            changecounts(allcounts,allstrings, special, categorymax);
        }
        // if(categorymin == upper)
        // {
        //     changeletterto = upper[upper.size()-(i+1)];
        // }
        // else if(categorymin == lower)
        // {
        //     changeletterto = lower[lower.size()-(i+1)];
        // }
        // else if(categorymin == digit)
        // {
        //     changeletterto = digit[digit.size()-(i+1)];
        // }
        // else if(categorymin == special)
        // {
        //     changeletterto = special[special.size()-(i+1)];
        // }
        // else
        // {
        //     changeletterto = '@';
        //     changecounts(allcounts,allstrings, special, categorymax);
        // }
        // if(minstr.size() != 0)
        // {
            
        //     changeletterto = minstr[0];
        //     // std::size_t poschange = minstr.find(changeletter) ;
        //     // if(poschange != std::string::npos)
        //     // {
        //     //     changeletterto = minstr[poschange];
        //     //     changecounts(allcounts, allstrings, categorymin, categorymax); 
        //     // }
        //     // else
        //     // {
        //     //     changeletterto = '!';
        //     //     changecounts(allcounts, allstrings, special, categorymax); 
        //     // }
            
        // }
        // else
        // {
        //     changeletterto = '@';
        //     changecounts(allcounts,allstrings, special, categorymax);
        // }


        std::size_t pos = strongerpass.find(changeletter) ;


        if(iterat == 0)
        {
            std::cout <<"change letter from " << changeletter << " at: "<< strongerpass.find(changeletter) << " to: " << changeletterto << endl;
            cout << allcounts[0]<< allcounts[1] << allcounts[2]<< allcounts[3] << endl;

        }
        
        if(pos != std::string::npos)
        {
            
            strongerpass[pos] = changeletterto;
        }
        else
        {
            break;
        }

        //strongerpass[strongerpass.find(changeletter)] = changeletterto;
        
        if(iterat == 0)
        {
            cout<< "final password: " << strongerpass << endl;
        }
        
        
    }
    iterat++;

    //int counts[4] = {uppercount,lowercount,digitcount,specialcount};




    return strongerpass;
}





int main(int argc, char* argv[])
{
    int iterat = 0;

    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file." << std::endl;
        return 1;
    }

    std::string addstr = ".strength"; 
    std::string outputFileName = argv[1] + addstr;

    std::ofstream outputFile(outputFileName);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file." << std::endl;
        return 1;
    }

    std::string password;
    while (std::getline(inputFile, password)) {

        std::string strengthenedPassword = strengthen(password, iterat);

        outputFile << strengthenedPassword << std::endl;
    }

    inputFile.close();
    outputFile.close();

    

    return 0;
}