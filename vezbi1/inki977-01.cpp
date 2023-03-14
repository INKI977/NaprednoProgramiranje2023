#include <iostream>
using namespace std;
  
// funkcija za razgranuvanje na nizata
void heapify(int arr[], int n, int root)
{
   int largest = root; // ova pretstavuva brojot vo nizata so najgolema vrednost, se narekuva koren (root)
   int l = 2*root + 1; // leviot element od korenot
   int r = 2*root + 2; // desniot element od korenot
  
   // se proveruva dali levatiot elemen(child) e pogolem od korenot
   if (l < n && arr[l] > arr[largest])
   largest = l;
  
   // se proveruva dali desnatiot element(child) e pogolem od bilo koj element
   if (r < n && arr[r] > arr[largest])
   largest = r;
  
   // dokolku izbraniot koren ne e najgolemata vrednost, se zamenuva so pomosh na swap funkcija so prethodno pronajdenata maksimalna vrednost
   if (largest != root)
      {
      //ovde se vrshi zamenata na korenot so najgolemiot element
      swap(arr[root], arr[largest]);
  
      // funkcijata e rekurzivna, se povikuva samata sebe se dodeka ne se razgrani celata niza
      heapify(arr, n, largest);
      }
}
  
// ovde se koristi sortiranje preku razgranuvanje na nizata
void heapSort(int arr[], int n)
{
   // ovde se razgranuva nizata, so pogornata funkcija
   for (int i = n / 2 - 1; i >= 0; i--)
   heapify(arr, n, i);
  
   // se vadat elementite od grankite eden po eden
   for (int i=n-1; i>=0; i--)
   {
      // tekovniot koren se nosi na krajot po pretpostvaka deka e najgolem broj
      swap(arr[0], arr[i]);
  
      // nizata se razgranuva povtorno, no so drug koren, toj e najgolemiot broj od nesortiranata niza
      heapify(arr, i, 0);
   }
}
  
/* Pechatenje na niza, bez razlika dali bila sortirana ili ne */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  

int main()
{
   int heap_arr[] = {int('h'),int('r'),int('i'),int('s'),int('t'),int('i'),int('j'),int('a'),int('n'),int('g'),int('o'),int('r'),int('k'),int('o'),int('v'),int('I'),int('N'),int('K'),int('I'),int('9'),int('7'),int('7')};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);
   cout<<"Vlezna niza"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sortirana niza"<<endl;
   displayArray(heap_arr, n);
}
