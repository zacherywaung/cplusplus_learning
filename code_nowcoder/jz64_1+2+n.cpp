// JZ_64  求1+2+3+n
//求1+2+3+...+n，要求不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）。

class Solution {
public:
    class Sum{
    public:
        Sum()
        {
            _ret += _i;
            ++_i;
        }
    };

    int Sum_Solution(int n) {
        Sum a[n];
        return _ret;  
    }
private:
    static int _i;
    static int _ret;
};
int Solution::_i = 1;
int Solution::_ret = 0;