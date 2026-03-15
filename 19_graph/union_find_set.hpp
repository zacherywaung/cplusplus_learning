#ifndef _UNION_FIND_SET_
#define _UNION_FIND_SET_

#include <vector>

namespace UnionFindSetModule
{
    class UnionFindSet
    {
    public:
        UnionFindSet(int size)
            :_ufs(size, -1)
        {}

        int FindRoot(int index)
        {
            int root = index;
            while(_ufs[root] >= 0)
            {
                root = _ufs[root];
            }
            // compress path
            while(_ufs[index] >= 0)
            {
                int parent = _ufs[index];
                _ufs[index] = root;
                index = parent;
            }
            return root;
        }

        bool Union(int index1, int index2)
        {
            int root1 = FindRoot(index1);
            int root2 = FindRoot(index2);
            if(root1 == root2)
            {
                return false;
            }
            // add small set to large set
            if(root1 > root2)
            {
                std::swap(root1, root2);
            }
            _ufs[root1] += _ufs[root2];
            _ufs[root2] = root1;
            return true;
        }

        ~UnionFindSet()
        {}
    private:
    std::vector<int> _ufs;
    };
}




#endif