Question-
  
  The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

  For example, for arr = [2,3,4], the median is 3.
  For example, for arr = [2,3], the median is (2 + 3) / 2 = 2.5.
  Implement the MedianFinder class:

  MedianFinder() initializes the MedianFinder object.
  void addNum(int num) adds the integer num from the data stream to the data structure.
  double findMedian() returns the median of all elements so far. Answers within 10-5 of the actual answer will be accepted.


  Example 1:

  Input
  ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
  [[], [1], [2], [], [3], []]
  Output
  [null, null, null, 1.5, null, 2.0]
  
Solution-
    
    
    
    class MedianFinder {
    public:
        priority_queue<int, vector<int>, greater<int> > mini;
      priority_queue<int> maxi;
        MedianFinder() { }

        void addNum(int num) {
            if(maxi.size()==0 or maxi.top()>num) maxi.push(num);
            else mini.push(num);

            if(maxi.size()>mini.size()+1)
            {
                mini.push(maxi.top());
                maxi.pop();
            }
            else if(mini.size()>maxi.size()+1)
            {
                maxi.push(mini.top());
                mini.pop();
            }

        }

        double findMedian() {
            if(size(maxi)==size(mini))
            {
                if(size(maxi)==0) 
                    return 0;
                double mean = (double)((maxi.top()+mini.top())/2.0);
                return mean;
            }

            return size(maxi)>size(mini)?maxi.top():mini.top();
        }
    };

    /**
     * Your MedianFinder object will be instantiated and called as such:
     * MedianFinder* obj = new MedianFinder();
     * obj->addNum(num);
     * double param_2 = obj->findMedian();
     */
