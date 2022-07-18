// You are given n activities with their start and finish times. Select the maximum number of activities that can be performed by a single person, assuming that a person can only work on a single activity at a time.
// Input Format
// The first line of input contains one integer denoting N.
// Next N lines contains two space separated integers denoting the start time and finish time for the ith activity. 
// Constraints
// 1 ≤ N ≤ 10^6
// 1 ≤ ai, di ≤ 10^9
// Output Format
// Output one integer, the maximum number of activities that can be performed
// Sample Input 1
// 6
// 1 2
// 3 4
// 0 6
// 5 7
// 8 9
// 5 9
// Sample Output 1
// 4
// Explanation:
// The four activities will be done at following time intervals:
// 1. 1 2
// 2. 3 4
// 3. 5 7
// 4. 8 9


bool cmp(pair<ll,ll>&a , pair<ll,ll>& b){
    return (a.second < b.second);
}

void solve(){
    int n;
    cin>>n;
    vector<pair<ll, ll>> a(n);
    for(int i = 0; i < n; i++){
        cin>>a[i].first>>a[i].second;
    }
    int et = -1;
    int c = 0;
    sort(a.begin(), a.end(), cmp);
    for(int i = 0; i < n; i++){
        if(et == -1){
            et = a[i].second;
            c++;
            continue;
        }
        if(a[i].first < et && et <= a[i].second){
            continue;
        }
        else{
            c++;
            et = a[i].second;
        }
    }
    cout<<c<<endl;
}