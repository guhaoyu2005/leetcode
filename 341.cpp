/*
Date: 2016-11-23
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class NestedIterator {
public:
    vector<int> nList;
    int currPos = 0;


    void fillTheVector(vector<NestedInteger> &list) {
	for (auto i: list) {
		if (i.isInteger()) {
			nList.push_back(i.getInteger());
		}
		else {
			fillTheVector(i.getList());
		}
	}
    }




    NestedIterator(vector<NestedInteger> &nestedList) {
        	for (auto i:nestedList) {
		if (i.isInteger()) {
			nList.push_back(i.getInteger());
		}
		else {
			fillTheVector(i.getList());
		}
	}
    }




    int next() {
        	int ret= nList[currPos];
	currPos++;
	return ret;
    }


    bool hasNext() {
	    if (currPos+1<=nList.size() ) return 1;
		else return 0;
    }
};


/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
