class MedianFinder {
    //Dekho simple question hai
    // agar na samajh aaye to
    // ye dekho https://www.youtube.com/watch?v=EcNbRjEcb14

    //hum two halves mein divide kar lenge
    //adha median ke pehle aur adha median ke baad

    //fir dono pq's ke size check kar lenge
    //agar +1 se jyada size hai, to disburse kar lenge

    //fir median return karte time size check kar lenge
    //aur jiska jyada uska top return
    //agar same to average of top elements (a+b)/2

public:
    priority_queue<int, vector<int>, greater<int>>minHeap;
    priority_queue<int> maxHeap;
    MedianFinder() 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        std::cout.tie(NULL);
    }
    
    void addNum(int num) {
        cout<<num;
        if(maxHeap.empty() || maxHeap.top()>num)
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        if(maxHeap.size()>minHeap.size()+1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if(minHeap.size()>maxHeap.size()+1)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if(maxHeap.size()>minHeap.size())
        {
            return  static_cast<double>(maxHeap.top());
        }
        else if(maxHeap.size()==minHeap.size())
        {
            return static_cast<double>(maxHeap.top()+minHeap.top())/2;
        }
        return static_cast<double>(minHeap.top());
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */