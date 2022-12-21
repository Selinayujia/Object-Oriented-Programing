// rec13_test.cpp

#include <iostream>
#include <fstream>
#include <vector>      // task 1
#include <list>        // task 2
#include <algorithm>   // task 3
#include <set>         // task 20
#include <map>         // task 22
using namespace std;

//template <typename T>
//T myFind(T start,T stop) {
//    while (start != stop) {
//        ++start;
//    }
//}

//void foo(const list<int>& alist)
//{
//    for(list<int>::iterator it= alist.begin();it!=alist.end();++it)
//    {
//        cout<<*it<<" ";
//    }
//}
list<int>::iterator myFind(list<int>::iterator start,
                            list<int>::iterator stop, int target) {
    while (start != stop) {
        if (*start == target) return start;
        ++start;
    }
    return stop;
}

template <typename T, typename U>
T myTempFind(T start,T stop, U target) {
    while (start != stop) {
        if (*start == target) return start;
        ++start;
    }
    return stop;
}

struct is_even
{
    bool operator() (int n) { return n % 2 == 0; }
};

void foo(const list<int>& alist)
{
    for(list<int>::const_iterator it= alist.begin();it!=alist.end();++it)
    {
        cout<<*it<<" ";
    }
}
void foo1(const list<int>& alist)
{
    for(const int i: alist)
    {
        cout<<i<<" ";
    }
}
list<int>::const_iterator find(const list<int>& alist, int target) {
    for(list<int>::const_iterator it= alist.begin();it!=alist.end();++it)
    {
        if(*it==target)
        {
            return it;
        }
    }
    return alist.end();
}
auto find2(const list<int>& alist, int target) {
    for(auto it= alist.begin();it!=alist.end();++it)
    {
        if(*it==target)
        {
            return it;
        }
    }
    return alist.end();
}
//list<int>::iterator find3(list<int>::iterator start,
//                            list<int>::iterator stop, int target) {
//    while (start != stop) {
//        if (*start == target) return start;
//        ++start;
//    }
//    return stop;
//}
bool is_even(int a)
{
    return a%2==0;
}

int main() {
    // 1. Create a vector with some values and display using ranged for

    cout << "Task 1:\n";
    vector<int> vecOfInt;
    for(size_t i=0;i<10;++i)
    {
        vecOfInt.push_back(int(i*i));
    }
    for(int i : vecOfInt)
    {
        cout<<i<<" ";
    }
    cout << "\n=======\n";
    
    // 2. Initalize a list as a copy of values from the vector
    cout << "Task 2:\n";
    list<int> alist(vecOfInt.begin(), vecOfInt.end());
    for(int i:alist)
    {
        cout<<i<<" ";
    }
    
    
    cout << "\n=======\n";
    
    // 3. Sort the original vector.  Display both the vector and the list
    cout << "Task 3:\n";
    for(size_t i=0;i<vecOfInt.size()/2;++i)
    {
//        int temp=vecOfInt[i];
//        vecOfInt[i]=vecOfInt[vecOfInt.size()-1-i];
//        vecOfInt[vecOfInt.size()-1-i]=temp;
        sort(vecOfInt.begin(),vecOfInt.end());
        
    }
    
    for(int i : vecOfInt)
    {
        cout<<i<<" ";
    }
    cout << "\n=======\n";
    for(int i:alist)
    {
        cout<<i<<" ";
    }
    cout << "\n=======\n";
    
    // 4. print every other element of the vector.
    cout << "Task 4:\n";
    for(size_t i=0;i<vecOfInt.size();++i)
    {
        if(int(i)%2!=0)
        {
            cout<<vecOfInt[i]<<" ";
        }
    }
    
    cout << "\n=======\n";
    
    // 5. Attempt to print every other element of the list using the
    //    same technique.
    cout << "Task 5:\n";
    for(size_t i=0;i<alist.size();++i)
    {
        if(int(i)%2!=0)
        {
            //cout<<alist[i]<<" ";
        }
    }
    
    cout << "\n=======\n";
    
    //
    // Iterators
    //
    
    // 6. Repeat task 4 using iterators.  Do not use auto;
    cout << "Task 6:\n";
    for(vector<int>::iterator it= vecOfInt.begin();it!=vecOfInt.end();++it)
    {
        cout<<*it<<" ";
    }
    
    cout << "\n=======\n";
    
    // 7. Repeat the previous task using the list.  Again, do not use auto.
    //    Note that you cannot use the same simple mechanism to bump
    //    the iterator as in task 6.
    cout << "Task 7:\n";
    for(list<int>::iterator it= alist.begin();it!=alist.end();++it)
    {
        cout<<*it<<" ";
    }
    cout << "\n=======\n";
    
    // 8. Sorting a list
    cout << "Task 8:\n";
    for(list<int>::iterator it= alist.begin();it!=alist.end();++it)
    {
        alist.sort();
        cout<<*it<<" ";
    }
    cout << "\n=======\n";
    
    // 9. Calling the function to print the list
    cout << "Task 9:\n";
    foo(alist);
    cout<<endl;
    cout << "=======\n";
    
    // 10. Calling the function that prints the list, using ranged-for
    cout << "Task 10:\n";
    foo1(alist);
    cout<<endl;
    cout << "=======\n";
    
    //
    // Auto
    //
    
    // 11. Calling the function that, using auto, prints alterate
    // items in the list
    cout << "Task 11:\n";
    for(auto it= alist.begin();it!=alist.end();++it)
    {
        
        cout<<*it<<" ";
        
    }
    cout<<endl;
    cout << "=======\n";
    
    
    // 12.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 12:\n";
    list<int>::const_iterator it=find(alist,81);
    if(it!=alist.end())
    cout<<*it<<endl;
    
    cout << "=======\n";
    
    // 13.  Write a function find that takes a list and value to search for.
    //      What should we return if not found
    cout << "Task 13:\n";
    auto it2=find2(alist,81);
    if(it2!=alist.end())
    {cout<<*it2<<endl;}
    cout << "=======\n";
    
    //
    // Generic Algorithms
    //
    
    // 14. Generic algorithms: find
    cout << "Task 14:\n";
    auto if_find=find(alist.begin(), alist.end(), 81);
    if(if_find!=alist.end())
    {cout<<*if_find<<endl;}
    cout << "=======\n";
    
    // 15. Generic algorithms: find_if
    cout << "Task 15:\n";
    auto answer=find_if(alist.begin(), alist.end(), is_even);
    if(answer!=alist.end())
    {cout<<*answer<<endl;}
    cout << "=======\n";
    
    // 16. Functor
    cout << "Task 16:\n";
    struct is_even anum;
    auto result=find_if(alist.begin(), alist.end(),anum );
    if(result!=alist.end())
    {cout<<*result<<endl;}
    
    cout << "=======\n";
    
    // 17. Lambda
    cout << "Task 17:\n";
    auto ans=find_if(alist.begin(), alist.end(),[](int n)->bool{return n%2==0;});
    if(ans!=alist.end())
    {cout<<*ans<<endl;}
    
    
    
    cout << "=======\n";
    
    // 18. Generic algorithms: copy to an array
    cout << "Task 18:\n";
    int arr[alist.size()];
    copy(alist.begin(),alist.end(),arr);
    for (int i : arr)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    cout << "=======\n";
    
    //
    // Templated Functions
    //
    
    // 19. Implement find as a function for lists
    cout << "Task 19:\n";
    
    auto res=myFind(alist.begin(), alist.end(),81 );
    if(res!=alist.end())
    {cout<<*res<<endl;}
    
    
    
    cout << "=======\n";
    
    // 20. Implement find as a templated function
    cout << "Task 20:\n";
    
    auto resu=myTempFind(alist.begin(), alist.end(),81 );
    if(resu!=alist.end())
    {cout<<*resu<<endl;}
    
    
    
    cout << "=======\n";
    
    //
    // Associative collections
    //
    
    // 21. Using a vector of strings, print a line showing
    cout << "Task 21:\n";
    ifstream ifs("pooh-nopunc.txt");
    if(!ifs){
        cout<<"file not found";
        exit(1);
    }
    vector<string> storage;
    while(ifs){
        string aword;
        
        ifs >> aword;
        
        if(find(storage.begin(), storage.end(), aword)==storage.end()){
            storage.push_back(aword);
        }
        
    }
//    for(size_t i =0;i<storage.size();++i)
//
//    {
//        cout<<storage[i]<<" ";
//    }
//    cout<<endl;
    ifs.close();
    
    cout << "\n=======\n";
    
    // 22. Repeating previous step, but using the set
    cout << "Task 22:\n";
    set<string>abunch;
    ifstream file("pooh-nopunc.txt");
    if(!file){
        cout<<"file not found";
        exit(1);
    }
    while(file){
        string aword;
        
        file >> aword;
        
        
        abunch.insert(aword);
        
    }
//    for(set<string>::iterator it = abunch.begin(); it!=abunch.end(); ++it){
//        cout << *it << " ";
//    }
    cout<<endl;
    file.close();
    
    
    
    cout << "=======\n";
    
    // 23. Word co-occurence using map
    cout << "Task 23:\n";
    map<string, vector<int>> wordMap;
    
    ifstream newfile("pooh-nopunc.txt");
    if(!newfile){
        cout<<"file not found";
        exit(1);
    }
    
    int counter = 0;
    while(newfile){
        string aword;
        
        newfile >> aword;
        ++counter;
        wordMap[aword].push_back(counter);
        
    }
    
    for(auto apair : wordMap){
        cout << apair.first;
        for(int it : apair.second){
            cout << " " << it;
        }
        cout << "\n";
    }
    
    newfile.close();
    
    
    
    
    
    cout << "=======\n";
}
