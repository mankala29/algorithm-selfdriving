#include <bits/stdc++.h>
#include <math.h>
#include <queue>
using namespace std;

//Creating a shortcut for an int, int pair
typedef pair<int, int> Pair;

//Creating a shortcut for location points
typedef pair<int, pair<int, int>> locPoint

//Creating passenger details for incoming requests
typedef pair<int, Pair, Pair> pDetails

//Custom comparator 
auto cmp = [](Pair a, Pair b){
	int x1 = a.first * a.first;
    int y1 = a.second * a.second;
    int x2 = b.first * b.first;
    int y2 = b.second * b.second;
	
	//using k-closest points to the origin
	//can be modified to closest points to the cab
	return (x1 + y1) > (x2 + y2);
}

//Create a priority queue to insert passenger details in minimum sort of source location
priority_queue<pDetails, vector<pDetails>, greater<pDetails.second.first> > passenger;

//Variable to keep a count of every step made by the cab
int timeStep = 0;

//Utility function to check whether the cell is valid or not
bool isValid(int row, int col){
	return (row >=0) && (row < ROW) && (col >= 0) && (col < COL);
}

//Utility function to check whether a given cell is blocked or not
bool isUnblocked(int grid[][COL], int row, int col){
	
	if(grid[row][col] == 1){
		return (true);
	else
		return (false);
}

//Check if the source and destination are the same locations
bool isDestination(int row, int col, Pair dest){
	if (row == dest.first && col == dest.second){
		return (true);
	else
		return (false)
}

void gridSearch(vector<vector<int>>& grid, Pair src, Pair dest){
	//Check for source out of bounds
	if (isValid(src.first, src.second) == false){
		printf("Invalid source\n");
		return;
	}
	
	//Check for destination out of bounds
	if (isValid(dest.first, dest.second) == false){
		printf("Invalid destination\n");
		return;
	}
	
	//If source or destination is blocked by an obstacle
	if (isUnblocked(grid, src.first, src.second) == false || isUnblocked(grid, dest.first, dest.second) == false){
		printf("Source or destination is blocked by an obstacle\n");
		return;
	}
	
	//If the source and destination are the same
	if (isDestination(src.first, src.second, dest) == true){
		printf("Source and destination have the same location\n");
		return;
	}

	int nr = grid.size();
    if (!nr) return 0;
    int nc = grid[0].size();
	
	//Starting the grid traversal from the source to destination
	for(int r = src.first; r < nr; ++r){
		for(int c = src.second; c < nc; ++c){
			if(isDestination(r, c, passSrc) == true){ //check if destination has been reached
				break;
			}
			if(grid[r][c] == '0'){
				dfs(grid, r, c, passSrc);
			}
		}
	}
	
}

void passengerDetails(int pNo){

	int sf = sc = 0;
	cout << "Where are you located at?";
	cin >> sf >> sc;
	Pair src = make_pair(sf, sc);
	
	int df = dc = 0;
	cout << "Where do you want to go?";
	cin >> df >> dc;
	Pair dest = make_pair(df, dc);
	
	//Create the passenger location
	pDetails = make_pair(++pNo, src, dest);
	
	//Inserts the passenger location into the priority queue
	passenger.push(pDetails);
	
}

void getSuccessors(vector<vector<int>>& grid){
		
	int pNo = 0;
	//Get the details of the existing passengers
	passengerDetails(pNo);
	
	vector<int> optimalTimeCab;
	vector<int> optimalTimePassenger;
	
	while(!passenger.empty()){
		
		//Fetch the source values from the passenger of priority that is closest using min queue
		passSrc = make_pair(passenger.top().second.first, passenger.top().second.second);
		
		//Fetch the destination values from all the passengers of the highest priority using min queue
		passDest = make_pair(passenger.top().third.first, passenger.top().third.second);
		
		//Call grid search for the cab to go to the passenger's source point
		gridSearch(grid, src, passSrc);
		optimalTimeCab.push_back(timeStep); //insert time step taken for the cab to get to a location
		
		//Call grid search for the cab to go from the passenger's source to the destination
		gridSearch(grid, passSrc, passDest);
		optimalTimePassenger.push_back(timeStep); //insert time step taken for the cab to take a passenger from source to destination
		optimalTimeCab.push_back(timeStep); //insert the time step for passenger journey
		
		passenger.pop();
	}
	
	//Call cost function
	costFunction(optimalTimeCab, optimalTimePassenger);
}	

int costFunction(vector<int> costFunction1, vector<int> costFunction2){

	//Calculate total time taken for the cab -> Time to reach the source point + time to reach destination of the last passenger
	int cabTime =  *max_element(costFunction1.begin(), costFunction1.end());
	
	//Calculate total time taken for the passenger -> from source to destination with pickups in between
	int passengerTime = return *max_element(costFunction2.begin(), costFunction2.end());
	
	return cabTime, passengerTime;
}

#Depth first search to navigate the shortest minimum path
void dfs(vector<vector<char>>& grid, int r, int c, Pair dest){
	int nr = grid.size();
	int nc = grid[0].size();
	
	//Check if destination has arrived
	if (isDestination(r, c, dest) == true){
		cout << "The drop location has been reached at (" << dest.first << "," << dest.second << ")";
		return;
	}
	
	if (r - 1 >= 0 && grid[r-1][c] == '0' && isValid(r-1, c)){
		dfs(grid, r - 1, c); //navigates left 
		++timeStep;
	}
    if (r + 1 < nr && grid[r+1][c] == '0' && isValid(r+1, c)){
		dfs(grid, r + 1, c); //navigates right 
		++timeStep;
	}
    if (c - 1 >= 0 && grid[r][c-1] == '0' && isValid(r, c-1)){
		dfs(grid, r, c - 1); //navigates upward 
		++timeStep;
	}
    if (c + 1 < nc && grid[r][c+1] == '0' && isValid(r, c+1)){
		dfs(grid, r, c + 1); //navigates downward
		++timeStep;
	}
}
	
void main(){

	#Dummy grid
	int grid[ROW][COL]
        = { { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 1 },
            { 1, 1, 1, 0, 1, 1, 0, 1, 0, 1 },
            { 0, 0, 1, 0, 1, 0, 0, 0, 0, 1 },
            { 1, 1, 1, 0, 1, 1, 1, 0, 1, 0 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
            { 1, 0, 0, 0, 0, 1, 0, 0, 0, 1 },
            { 1, 0, 1, 1, 1, 1, 0, 1, 1, 1 },
            { 1, 1, 1, 0, 0, 0, 1, 0, 0, 1 } };
	
	int first = 0;
	int second = 0;
	
	//The source point of the car
	cout <<"Enter the source points:\t";
	cin >> first >> second;
	Pair src = make_pair(first, second);

	//Function can be called the number of times passengers request for locations
	//Call to function locate the passenger and their destinations
	getSuccessors(grid);
}	
	






