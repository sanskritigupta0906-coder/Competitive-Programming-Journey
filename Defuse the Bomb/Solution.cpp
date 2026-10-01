class Solution {
public:

//when k is positive : we have to add the next k elements
vector<int> positive(vector<int>& arr, int k) {

    vector<int> ans;

    for(int i = 0; i < arr.size(); i++) {

        //start sum and y again for every element
        int sum = 0;
        int y = k;

        //start from the next element
        int p1 = i + 1;

        while(y--) {

            //if we reach the end, go back to the start
            if(p1 >= arr.size())
                p1 %= arr.size();

            sum += arr[p1];

            //move to the next element
            p1++;
        }

        //store the sum
        ans.push_back(sum);
    }

    return ans;
}


//when k is negative : we have to add the previous |k| elements
vector<int> negative(vector<int>& arr, int k) {

    vector<int> ans;

    for(int i = 0; i < arr.size(); i++) {

        //start sum and y again for every element
        int sum = 0;
        int y = abs(k);

        //start from the previous element
        int p1 = i - 1;

        while(y--) {

            //if we go before 0, go back to the last index
            if(p1 < 0)
                p1 += arr.size();

            sum += arr[p1];

            //move to the previous element
            p1--;
        }

        //store the sum
        ans.push_back(sum);
    }

    return ans;
}


vector<int> decrypt(vector<int>& code, int k) {

    vector<int> res;

    //when k = 0 : replace every element with 0
    if(k == 0) {

        for(int i = 0; i < code.size(); i++)
            res.push_back(0);

        return res;
    }

    //when k is positive : call positive()
    if(k > 0)
        res = positive(code, k);

    //when k is negative : call negative()
    else
        res = negative(code, k);

    return res;
  }
};
