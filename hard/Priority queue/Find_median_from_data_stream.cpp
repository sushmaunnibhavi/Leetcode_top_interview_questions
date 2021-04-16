/*Question Link: https://leetcode.com/problems/find-median-from-data-stream/*/

class MedianFinder {
private:
    priority_queue<int> firstQ; // max_heap for the first half
    priority_queue<int, vector<int>,greater<int> > secQ; // min_heap for the second half
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        if(firstQ.empty() || (firstQ.top()>num))//We do this because we need mid elements
            firstQ.push(num); 
        else 
            secQ.push(num); 
     
        if(firstQ.size() > (secQ.size()+1))
        {
            secQ.push(firstQ.top());
            firstQ.pop();
        }
        else if(firstQ.size()+1<secQ.size())
        {
            firstQ.push(secQ.top());
            secQ.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if(firstQ.size() == secQ.size()) return firstQ.empty()?0:( (firstQ.top()+secQ.top())/2.0);
        else return (firstQ.size() > secQ.size())? firstQ.top():secQ.top(); 
    }
};

/*

Time Complexity:
for addNum func:For adding element to priority queue:O(logn)
to find median:O(1)

Hence time complexity is O(logn)

*/