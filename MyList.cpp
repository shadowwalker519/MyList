#include<iostream>
using namespace std;

class out_of_range{}; 
class high_start{};
class empty_list{};

template<class T> class MyList;
template<class T> ostream & operator << (ostream &os, const MyList<T> &obj);

template<class T>
class MyList{
private:
	T *a;
	int size;
	int element;
	void double_space(); //This funciton doubles the space when it is not enough.
public:
	MyList(){
		size = 100;
		element = 0;
		a = new T [size];
	}
	MyList(int num, const T &item); //This function put num into the list t times.
	MyList(const MyList &l); //This function copies another MyList.
    	MyList(T* arr, int len); //This function constructs MyList with the first len numbers of arr.

	void push(const T &item); //This function adds the item to the last of the list. 
	T pop(); //This function erases the last element of MyList and returns the value of it.
	void insert(int index, const T &item); //This function inserts item to the location index.
	void clean(); //This function cleans the list 
	int get_size(); //This function returns the number of the elements of the list.
	void erase(int start, int end); //This function deletes the elements in mylist from start to end, including both bounderies.
	T get_item(int index); //This function returns the element with the location index.
	MyList get_item(int start, int end); //This function returns elements of mylist as a new list, including both boundaries. Negative numbers are acceptable.
	int count(const T &item); //This function returns the number of elements with the same value as item in the list.
	void remove(const T &item); //This function deletes the first element with the same value as item in the list.

	friend MyList<T> operator + (const MyList<T> &l1, const MyList<T> &l2){ //This operator combines two lists together.
		int *a;
		int len = l1.element+l2.element;
		a = new int [len];
		for(int i = 0; i < l1.element; ++i) a[i] = l1.a[i];
		for(int i = l1.element; i < len; ++i) a[i] = l2.a[i-l1.element];
		MyList<T> list(a,len);
		delete [] a;
		return list;	
	}
	
	friend MyList<T> operator + (const MyList<T> &l1, const T &item){ //This operator is same as push fucntion except the original list is not changed.
		MyList<T> l2(l1);
		l2.push(item);
		return l2;
	}
	
	MyList &operator = (const MyList &l); //This operator assigns the value.
	MyList &operator += (const T &item); //This operator is same as the push function.
	MyList &operator += (const MyList &l); //This operator adds another list to the list.
	T &operator [](int index); //This operator returns the element with the location index.
	friend ostream & operator <<<T> (ostream &os, const MyList<T> &obj);//This operator output the target if it can be output directly like int.

	void sort(bool less=true); //This function sorts the list with quick sort method. 
	void reverse(); //This function reverses the elements in the list.

	~MyList(){delete [] a;}
};

template <class T>  
void MyList<T>::double_space(){
	T *b = a;
	size *= 2; 
	a = new T [size];
	for(int i = 0; i < element; ++i) a[i] = b[i];
	delete [] b;
} 

template <class T> 
MyList<T>::MyList(int num, const T &item){
	element = num;
	size = num;
	a = new T [num];
	for(int i = 0; i < num; ++i) a[i] = item;
}
	
template <class T> 	
MyList<T>::MyList(const MyList &l){
	size = l.size;
		element = l.element;
	a = new T [size];
	for(int i = 0; i < element; ++i) a[i] = l.a[i];
}

template <class T> 
MyList<T>::MyList(T* arr, int len){
	size = len;
	a = new T [size];
	for(int i = 0; i < size; ++i) a[i] = arr[i];
	element = size;
}

template <class T> 
void MyList<T>::push(const T &item){
	if(element == size) this -> double_space();
	a[element++] = item;	 
}

template <class T> 
T MyList<T>::pop(){
	try{
		if(element == 0) throw empty_list();
		return a[--element];
	}
	catch(empty_list){
		cout << "Error! Empty list!" << endl;
		throw empty_list();
	}
}

template <class T> 
void MyList<T>::insert(int index, const T &item){
	if (index < 0) index += element;
	try{
		if(index > element || index < 0) throw out_of_range();
		if(element == size) this -> double_space();
		++ element;
		for(int i = element-1; i > index; i--) a[i] = a[i-1];
		a[index] = item;
	}
	catch(out_of_range){
		cout << "Error! Index out of range!" << endl;
	}	
}

template <class T> 
void MyList<T>::clean(){
	element = 0;
}

template <class T> 
int MyList<T>::get_size(){
	return element;
}

template <class T> 
void MyList<T>::erase(int start,int end){
	if(start < 0) start += element;
	if(end < 0) end += element;
	try{
		if(start > end ) throw high_start();
		if(end > element-1 || start < 0) throw out_of_range();
		int len = element-end-1;
		for(int i = 0; i < len; ++i) a[start+i] = a[end+i+1];
		element -= (end-start+1);
	}
	catch(high_start){
		cout << "Error! Start higher than end!" << endl;
	}
	catch(out_of_range){
		cout << "Error! Index out of range!" << endl;
	}
}

template <class T> 
T MyList<T>::get_item(int index){
	if (index < 0) index += element;
	try{
		if(index > element-1 || index < 0) throw out_of_range();
		return a[index];
	}
	catch(out_of_range){
		cout << "Error! Index out of range!" << endl;
		exit(1);
	}	
}

template <class T> 	
MyList<T> MyList<T>:: get_item(int start, int end){
	if(start < 0) start += element;
	if(end < 0) end += element;
	try{
		if (start > end) throw high_start();
		if (start < 0 || end > element-1) throw out_of_range();
		MyList<T> array(a+start, end-start+1);
		return array;
	}
	catch(high_start){
		cout << "Error! Start higher than end!" << endl;
		MyList<T> array;
		return array;
	}
	catch(out_of_range){
		cout << "Error! Index out of range!" << endl;
		MyList<T> array;
		return array;
	}
}

template <class T> 
int MyList<T>::count(const T &item){
	int result = 0;
	for(int i = 0; i < element; ++i){
		if(a[i] == item) ++result;
	}
	return result;
} 

template <class T> 
void MyList<T>::remove(const T &item){
	for(int i = 0; i < element; ++i) {
		if(a[i] == item){
		    erase(i,i);
		    break;
		}
	}
}

template <class T> 
MyList<T> & MyList<T>::operator = (const MyList &l){
	if (this == &l) return *this;
	size = l.size;
	element = l.element;
	a =  new int [size];
	for(int i = 0; i<element; ++i) a[i] = l.a[i];
	return *this;
}

template <class T> 	
MyList<T> & MyList<T>::operator += (const T &item){
	this->push(item);
	return *this;
}

template <class T>
MyList<T> & MyList<T>::operator += (const MyList &l){
	int len = element+l.element;
	while(size < len) this -> double_space();
	for(int i = 0; i < l.element; ++i) a[element+i] = l.a[i];
	element = len;
	return *this;
} 

template <class T>
T & MyList<T>::operator [](int index){
	if (index < 0) index += element;
	try{
		if(index > element-1 || index < 0) throw out_of_range();
		return a[index];
	}
	catch (out_of_range){
		cout << "Error! Index out of range!" << endl;
		exit(1);
	}	
} 

template <class T>
ostream & operator<<(ostream &os, const MyList<T> &obj){
	os << "[" ;
	if (obj.element != 0){
		for(int i = 0;i < obj.element-1; ++i) os << obj.a[i] << ", ";
		os << obj.a[obj.element-1];
	}
	os << "]";
	return os; 
}

template <class T> 
void quicksorttrue(T *s, int low, int high){  
    if(low < high){        
        int mid = low, x = high, tmp = s[low];  
        while(mid < x){  
            while(mid < x && s[x]>= tmp) --x;   
            if(mid < x) s[mid++] = s[x];  
            while(mid < x && s[mid]< tmp) ++mid;   
            if(mid < x) s[x--] = s[mid];  
        }  
        s[mid] = tmp;  
        quicksorttrue(s, low, mid - 1); 
        quicksorttrue(s, mid + 1, high);  
    }  
}  

template <class T>
void quicksortfalse(T *s, int low, int high){  
    if (low < high){        
        int mid = low, x = high, tmp = s[low];  
        while(mid < x){  
            while(mid < x && s[x]<= tmp) --x;   
            if(mid < x) s[mid++] = s[x];  
            while(mid < x && s[mid]> tmp) ++mid;   
            if(mid < x) s[x--] = s[mid];  
        }  
        s[mid] = tmp;  
        quicksortfalse(s, low, mid-1); 
        quicksortfalse(s, mid+1, high);  
    }  
}  

template <class T>
void MyList<T>::sort(bool less ){
	if (element != 0){
		if(less) quicksorttrue(a, 0, element-1);
		else quicksortfalse(a, 0, element-1);
	}
}

template <class T> 
void MyList<T>::reverse(){
	if(element != 0){
		int *b;
		b = new int [size];
		for(int i = 0; i < element; ++i) b[i] = a[element-i-1];
		delete [] a;
		a = b;
	}
}

int main(){
	MyList<int> a, b;
	int i;
	for (i=0; i<5; ++i)
		a.push(i); // a = [0, 1, 2, 3, 4]
	a[3] = 15; // a = [0, 1, 2, 15, 4]
	a.sort(); // a = [0, 1, 2, 4, 15]
	a.reverse(); // a = [15, 4, 2, 1, 0]
	a += 12; // a = [15, 4, 2, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a[i]<<endl;
    b = a.get_item(4, -3); // b = [] if start > end, return empty list.
	b = a.get_item(3, -1); // b = [1, 0, 12] 
	a += b; // a = [15, 4, 2, 1, 0, 12, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a.get_item(i)<<endl;
	cout<<a.count(5)<<endl;
	b.clean(); // b = []
	cout<<b.get_size()<<endl;
	a.erase(2, 5); // a = [15, 4, 0, 12] (It seems that the erase function is not achieved as intended. a should be [15, 4, 1, 0, 12] according to the notes given.)
	b = a + a; // b = [15, 4, 0, 12, 15, 4, 0, 12]
	b.insert(3, 116); // b = [15, 4, 0, 116, 12, 15, 4, 0, 12]
	b.remove(4); // b = [15, 0, 116, ...]
	cout<<b<<endl;
	MyList<double> c(10, 3.14);
	for (i=0; i<100; ++i)
		c.push(1.1*i);
	cout<<c.get_item(100, 105)<<endl;
	return 0;
}
