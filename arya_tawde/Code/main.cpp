#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

void createarray(string ,string*, int );
void insertionsort(string*, int);
void quicksort(string*, int, int);
int splitter(string*, int, int);

int main(int argc, char *argv[])
{

    int choice;

    string a = argv[1];
    string filenames = argv[2];

    int b = filenames.find('>');

    cout<< b <<endl;

    string inputfile = filenames.substr(1,b-1);
    string outputfile = filenames.substr(b+1, filenames.length());

    cout<< inputfile<< endl<< outputfile<< endl;

    if(a == "insertion")
        {choice = 1;
        cout<<"insertion"<< endl;}
    else
        {choice = 0;
        cout<<"quick"<< endl;}

    // Saving the original pointers to cin and cout
    streambuf *coutbuf = cout.rdbuf();
    streambuf *cinbuf  = cin.rdbuf();

    //Creating the streams for redirection to files
    ofstream out(outputfile);
    ifstream in(inputfile);

    //Redirecting cin and cout to the file streams
    cin.rdbuf(in.rdbuf());
    //cout.rdbuf(out.rdbuf());

    string input;

    while(getline(cin, input))
    {
        int insize = input.length();
        string* stringarray = new string[insize];
        createarray(input, stringarray, insize);
        if(choice)
            insertionsort(stringarray, insize);
        else
            quicksort(stringarray, 0, insize-1);


        int x= 0;
        while(x<insize)
        {
            if(stringarray[x] == input)
                break;
            x++;
        }

        string toencode= "";
        int y=0;
        while(y<insize)
        {
            toencode = toencode + stringarray[y].at(insize-1);
            y++;
        }

        cout<< x<< endl;

        int z =1;
        int counter = 1;
        char check = toencode.at(0);
        while(z<insize)
        {
            if(toencode.at(z)==check)
            {
                counter++;
            }
            else
            {
                cout<<counter<< check;
                counter = 1;
                check = toencode.at(z);
            }

            z++ ;
        }
        cout<<counter<< check;

        delete stringarray;
    }

    //Restore back.
    cin.rdbuf(cinbuf);
    cout.rdbuf(coutbuf);
}

void createarray(string input, string* stringarray, int insize)
{
    stringarray[0] = input;
    int x = 1;
    string temp = input;
    while(x < insize)
    {
        temp = temp.substr(1, insize) + temp.substr(0,1);
        stringarray[x] = temp;
        x++;
    }
}
void insertionsort(string* stringarray, int insize)
{
   int i,j;
   string key;
    for (i = 1; i < insize; i++)
    {
        key = stringarray[i];
        j = i - 1;

        while (j >= 0 && stringarray[j] > key)
        {
            stringarray[j + 1] = stringarray[j];;
            j = j - 1;
        }
        stringarray[j + 1] = key;
    }


}

void quicksort(string* stringarray, int low ,int high)
{
     if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
           at right place */
        int midindex = splitter(stringarray, low, high);

        // Separately sort elements before
        // partition and after partition
        quicksort(stringarray, low, midindex - 1);
        quicksort(stringarray, midindex + 1, high);
    }



}

int splitter(string* stringarray, int low ,int high)
{
    string pivot = stringarray[high];    // pivot
    int i = (low - 1);  // Index of smaller element

    for (int j = low; j <= high- 1; j++)
    {
        // If current element is smaller than or
        // equal to pivot
        if (stringarray[j] <= pivot)
        {
            i++;    // increment index of smaller element
            string temp = stringarray[i];
            stringarray[i]= stringarray[j];
            stringarray[j]= temp;
        }
    }


    string temp = stringarray[i+1];
    stringarray[i+1]= stringarray[high];
    stringarray[high]= temp;

    return (i + 1);
}

