/*
 * å®žçŽ°ä¸€ä¸ªlistç±»å‘½åä¸ºMyListï¼Œå…¶åŠŸèƒ½ä¸Žpythonæ•°ç»„ç±»ä¼¼ã€‚å¯ä»¥ç”¨æ•°ç»„å®žçŽ°ï¼Œä¹Ÿå¯ä»¥ç”¨é“¾è¡¨å®žçŽ°ã€‚
 * å¿…é¡»ä½¿ç”¨template <class T>ï¼Œä¸å…è®¸ä½¿ç”¨<iostream>ä»¥å¤–çš„åº“ã€‚
 * éœ€è¦å®žçŽ°çš„åŠŸèƒ½ä¸Žæµ‹è¯•ä»£ç è§ä¸‹ã€‚è¯·åŠ¡å¿…æžæ¸…æ¥šæ¯ä¸€é¡¹çš„æ„ä¹‰ï¼Œæ¯”å¦‚ä»€ä¹ˆæ—¶å€™éœ€è¦ç”¨å‹å…ƒå‡½æ•°ä»€ä¹ˆæ—¶å€™éœ€è¦constä»€ä¹ˆæ—¶å€™éœ€è¦&ã€‚
 * å½“æŸäº›ç”±ç”¨æˆ·æ­£å¸¸æ“ä½œå¯èƒ½äº§ç”Ÿçš„run time errorï¼ˆå¦‚popä¸€ä¸ªç©ºæ•°ç»„ï¼Œæˆ–è®¿é—®ä¸€ä¸ªè¶…å‡ºä¸‹æ ‡çš„å…ƒç´ ï¼‰ï¼Œ
 * è¯·ä½¿ç”¨try-catch-throwå¤„ç†é”™è¯¯ã€‚
 * ä»¥ä¸‹ç±»å®šä¹‰ä¸ä¿è¯å®Œå…¨æ­£ç¡®ï¼Œè¯·æ ¹æ®å®žé™…éœ€æ±‚ä¿®æ”¹ï¼Œä»¥å®žçŽ°æ ·ä¾‹åŠŸèƒ½ä¸ºä¸»ã€‚
 */

/* 
 * æœ¬ç»ƒä¹ ä¸æ¶‰åŠåˆ°è™šç±»å’Œç±»ç»§æ‰¿ï¼Œä½†æ˜¯æœŸæœ«è€ƒè¯•æˆ‘å°±ä¸çŸ¥é“äº†ã€‚å¦‚æžœæœ‰æ—¶é—´å¯ä»¥ç”¨ä¹¦ä¸Šçš„shapeç±»æ¥ç»ƒä¹ ã€‚
 */

#include<iostream>
using namespace std;

template<class T>
class MyList{
private:
	T *a;
	int size;
	void double_space();//æ•°ç»„å¤§å°ä¸å¤Ÿçš„æ—¶å€™å°†æ•°ç»„å¤§å°ç¿»å€çš„æ“ä½œã€‚
public:
	MyList(){
		size = 100;
		a = new int [size];
	}
	MyList(int num, const T &item);//å°†itemé‡å¤numæ¬¡å¡«å…¥æ•°ç»„ä¸­ã€‚
	MyList(const MyList &l);//æ·±å¤åˆ¶å¦å¤–ä¸€ä¸ªMyListã€‚
    MyList(T* arr, int len);//ä»¥arrçš„å‰lenä¸ªå…ƒç´ æž„é€ æ•°ç»„

	void push(const T &item);//å°†itemæ·»åŠ åœ¨MyListæœ€åŽã€‚
	T pop();//å°†MyListä¸­æœ€åŽä¸€ä¸ªå…ƒç´ åˆ é™¤ï¼Œå¹¶è¿”å›žè¿™ä¸ªåˆ é™¤çš„å…ƒç´ ã€‚
	void insert(int index, const T &item);//å°†itemæ’å…¥åˆ°placeå¤„ã€‚
	void clean();//æ¸…ç©ºæ•°ç»„ã€‚
	int get_size();//è¿”å›žMyListä¸­å…ƒç´ çš„æ•°é‡ã€‚
	void erase(int start, int end); //åˆ é™¤MyListä¸­ç¬¬startåˆ°ç¬¬endä½çš„å…ƒç´ ï¼ŒåŒ…æ‹¬ä¸¤è¾¹ã€‚
	T get_item(int index);//è¿”å›žç¬¬indexä¸ªå…ƒç´ ã€‚
	MyList get_item(int start, int end);//è¿”å›žMyListä¸­ç¬¬startåˆ°ç¬¬endä½çš„å…ƒç´ ï¼ŒåŒ…æ‹¬ä¸¤è¾¹ã€‚æ­¤å¤„éœ€è¦åƒpythonä¸€æ ·æŽ¥å—è´Ÿæ•°ï¼Œå…·ä½“è§æµ‹è¯•ä»£ç ã€‚
	int count(const T &item);//è¿”å›žMyListä¸­å’Œitemç›¸ç­‰çš„å…ƒç´ çš„ä¸ªæ•°ã€‚
	void remove(const T &item);//åˆ é™¤MyListä¸­ç¬¬ä¸€ä¸ªå’Œitemç›¸ç­‰çš„å…ƒç´ ã€‚


	friend MyList operator + (const MyList &l1, const MyList &l2); //åˆå¹¶ä¸¤ä¸ªMyList
    friend MyList operator + (const MyList &l1, const T &item); //åŒpush(T item)ï¼Œä½†ä¸ä¿®æ”¹l1ï¼Œè¿”å›žä¸€ä¸ªæ–°æ•°ç»„
	MyList &operator = (const MyList &l);//èµ‹å€¼
	MyList &operator += (const T &item);//åŒpush(T item)
	MyList &operator += (const MyList &l);//å°†ä¸€ä¸ªMyListåŠ å…¥åˆ°æœ¬ä¸ªMyListä¹‹åŽã€‚
	T &operator [](int index);//è¿”å›žç¬¬indexä¸ªå…ƒç´ ã€‚
	friend ostream & operator<<(ostream &os, const MyList &obj);//å¦‚æžœTæ˜¯å¯ä»¥ç›´æŽ¥coutçš„ç±»çš„è¯ï¼ˆæ¯”å¦‚intï¼‰ï¼ŒæŒ‰Pythonæ•°ç»„çš„æ ¼å¼è¾“å‡ºMyListä¸­çš„æ¯ä¸€ä¸ªå…ƒç´ ï¼Œä¾‹å¦‚ï¼š
    // [1, 2, 5, 4, 1]

	void sort(bool less=true);//å®žçŽ°ä¸€ä¸ªå¿«é€ŸæŽ’åºæˆ–å½’å¹¶æŽ’åºï¼Œå¯¹æ”¯æŒæ¯”è¾ƒè¿ç®—ç¬¦ï¼ˆ>=<ï¼‰çš„ç±»è¿›è¡ŒæŽ’åºã€‚
    // è‹¥less=trueï¼ŒæŒ‰ç…§ä»Žå°åˆ°å¤§æŽ’åˆ—ï¼Œå¦åˆ™æŒ‰ä»Žå¤§åˆ°å°æŽ’åˆ—
	void reverse();//å°†MyListçš„å…ƒç´ å€’è¿‡æ¥ã€‚

	~MyList(){delete [] a;}
};

int main(){
	MyList<int> a, b;
	int i;
	for (i=0; i<5; ++i)
		a.push(i);
    // a = [0, 1, 2, 3, 4]
	a[3] = 15; // a = [0, 1, 2, 15, 4]
	a.sort(); // a = [0, 1, 2, 4, 15]
	a.reverse(); // a = [15, 4, 2, 1, 0]
	a += 12; // a = [15, 4, 2, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a[i]<<endl;
    b = a.get_item(4, -3); // b = [] *è‹¥start > endï¼Œè¿”å›žç©ºæ•°ç»„
	b = a.get_item(3, -1); // b = [1, 0, 12] 
	a += b; // a = [15, 4, 2, 1, 0, 12, 1, 0, 12]
	for (i=0; i<a.get_size(); ++i)
		cout<<a.get_item(i)<<endl;
	cout<<a.count(5)<<endl;
	b.clean(); // b = []
	cout<<b.get_size()<<endl;
	a.erase(2, 5); // a = [15, 4, 0, 12]
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
