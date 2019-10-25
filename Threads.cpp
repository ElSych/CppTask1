#include <iostream> 
#include <thread>
#include <vector>
using namespace std; 
int countArray(vector<int> &arr, int len) { 
    for (int i = 0; i < len; i++) { 
        arr.at(i)++; 
    } 
} 
 
int printArray(vector<int> &arr, int len) { 
    for (int i = 0; i < len; i++) { 
        cout << arr.at(i) << ' '; 
    } 
}  
int main() { 
    int len = 10; 
    vector<int> arr(len); 
    thread func_thread(countArray, arr, len); 
    thread func_thread2(printArray, arr, len);  
    if (func_thread.joinable()) func_thread.join(); 
    if (func_thread2.joinable()) func_thread2.join(); 
    return 0; 
}
/* In file included from /usr/include/c++/6/thread:39:0,
                 from main.cpp:9:
/usr/include/c++/6/functional: In instantiation of ‘struct std::_Bind_simple<int (*(std::vector<int>, int))(std::vector<int>&, int)>’:
/usr/include/c++/6/thread:138:26:   required from ‘std::thread::thread(_Callable&&, _Args&& ...) [with _Callable = int (&)(std::vector<int>&, int); _Args = {std::vector<int, std::allocator<int> >&, int&}]’
<span class="error_line" onclick="ide.gotoLine('main.cpp',27)">main.cpp:27:44</span>:   required from here
/usr/include/c++/6/functional:1365:61: error: no type named ‘type’ in ‘class std::result_of, int))(std::vector&, int)>’
       typedef typename result_of<_Callable(_Args...)>::type result_type;
                                                             ^~~~~~~~~~~
/usr/include/c++/6/functional:1386:9: error: no type named ‘type’ in ‘class std::result_of, int))(std::vector&, int)>’
         _M_invoke(_Index_tuple<_Indices...>) */
