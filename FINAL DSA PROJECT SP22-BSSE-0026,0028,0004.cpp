#include <iostream>
#include <string>
#include "windows.h"
#include "conio.h"
#include "fstream"
#include <cstdio>
#include <iomanip>

using namespace std;

struct Flight {
  
    string flightNumber;
    string departure;
    string destination;
    int seats;
    int countseats;
    double basicprice;
    string *passengers;
    Flight* next;
    
};

class TravelPlanner {
    public:
        TravelPlanner() {
        head = NULL;
    }
    void addFlight(std::string flightNumber, std::string departure, std::string destination, int seats, double basic) {
        
		Flight* newFlight = new Flight;
        
		newFlight->flightNumber = flightNumber;
        
		newFlight->departure = departure;
        
		newFlight->destination = destination;
        
		newFlight->seats = seats;   
		
		newFlight->countseats = 0;  
		
		newFlight->next = head;
        
		newFlight->passengers = new string[newFlight->seats];
        
		newFlight->basicprice = basic;
        
		head = newFlight;
    	
    }
    void displayFlights() {
        Flight* current = head;
        while (current != NULL) {
        
		    cout << "Flight number: " << current->flightNumber << "             ";
        
		    cout << "Departure: " << current->departure << "             ";
        
		    cout << "Destination: " << current->destination << "             ";
        
		    cout << "Seats available: " << current->seats << "             ";
        
		    cout << "PER PASSENGER PRICE: "<< current->basicprice; 
        
		    cout << std::endl;
        
		    current = current->next;
        }
    }
    
    
    int BookAFlightForPerson(string f_number, string person)
    {
    	Flight* current = head;
        while (current != NULL && current->flightNumber != f_number) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Flight not found" << endl;
            return current->countseats;
        }
        else 
        {
        if (current->countseats == current->seats)
        {
        	cout << "SORRY THE SEATS ARE FULL \n\n";
        	return current->countseats;
		}
        current->passengers[current->countseats++] = person;
		cout << "BOOKED!!\n\n";
		}
		
		return current->countseats;
	}
	
	void displayFlightDetails(string f_number){
		
    	Flight* current = head;
        while (current != NULL && current->flightNumber != f_number) {
            current = current->next;
        }
        if (current == NULL) {
            cout << "Flight not found" << endl;
            return;
        }
        else
        {
        	cout << "Flight number: " << current->flightNumber << "|  ";
        
		    cout << "Departure: " << current->departure << "|  ";
        
		    cout << "Destination: " << current->destination << "|  ";
        
		    cout << "Total Seats : " << current->seats << "|  ";
        
			cout << "TOTAL SEATS RESERVED: "<<current->countseats<< "|  ";
        
			cout << "TOTAL AMOUNT THEY GET YET : "<< current->basicprice * current->countseats << " PKR \n ";
        
			cout << "REMAINING SEATS :" << current->seats - current->countseats<< "\n";
        
			cout << "TOP FIRST 10 PASSENGERS: "<<endl;
        	int i = 0 , count;
        	if (current->countseats < 10)
        	count = current->countseats;
        	else
        	count = 10;
        	while (i != count)
        	{
        		cout << current->passengers[i];
        		cout<<endl;
        		i+=1;
			}
		}
	}
	
	void updateFlightDetails()
	{
	string z,user,c,up_name, f_n;
	int flag=0;
	cout<<"ENTER FLIGHT NUMBER TO UPDATE THE NAME OF PERSON : ";
	cin>>f_n;
	Flight* current = head;
    while (current != NULL && current->flightNumber != f_n) {
        current = current->next;
    }
    if (current == NULL) {
        cout << "Flight not found" << endl;
        return;
    }else{
        
		
		if (current->countseats == current->seats)
        {
		cout << "SORRY THE SEATS ARE FULL \n\n";
		return;
		}    
    cout<<"ENTER NAME OF PERSON TO UPDATE : ";
	cin>>user;
	
	ifstream file1;
	ofstream file2;
	file2.open("temp.txt",std::ios_base::app);
	file1.open("flight.txt",std::fstream::in);
	
	while (getline(file1, c, '\t')) {
     if (c == user)
     {
     	// for file updation
     	
     	cout<<"ENTER A UPDATED NAME : ";
     	cin>>up_name;
     	file2<<up_name<<" ";
     	flag=1;
     	
	
     	// for linkedlist updation
	 	for (int i = 0 ; i < current->countseats ; i ++)
		if (current->passengers[i] == user) current->passengers[i] = up_name; 
			
	 }
       
    else
     file2<<c<<"\t";
	} 
	file1.close();
	file2.close();
	rename("temp.txt", "flight.txt");
	remove ("flight.txt");
	if(!flag)
	{
	cout<<"File Not Found !!\n";
	cout<<"Press any key to return !\n";
	getch();
	}
	else
	{
	cout<<"Update Successfully !!";
	cout<<"Press any key to return !";
	getch();
	}
		
		}
	
	
}
		
   private:
   Flight* head;
};


struct Hotel {
	
    string  room_numbers;
    string room_available;
    string hotel_name ;
    int rooms;
    int countrooms;
    int room_prices;
    string *Room;
    Hotel* next;
   
};

class Reservation {
public:
	
    Reservation() {
        head2 = NULL;
    }
        void addHotel(std::string hotel_name, std::string room_available, std::string room_numbers,double prices, int rooms) {
     
        Hotel* newHotel = new Hotel;
        
		newHotel->hotel_name = hotel_name;
        
		newHotel->room_available =room_available;
        
		newHotel->room_numbers =room_numbers;
        
		newHotel->rooms = rooms;  
        
		newHotel->countrooms = 0;    
        
		newHotel->next = head2;
        
		newHotel->Room = new string[newHotel->rooms];
        
		newHotel->room_prices = prices;
        
		head2 = newHotel;
   
    }
        void displayHotel() {
        Hotel* current2 = head2;
        while (current2 != NULL) {
         
		    cout << "HOTEL NAME: " << current2->hotel_name << "             ";
         
		    cout << "AVALABILITY OF ROOMS: " << current2->rooms << "             ";
         
		    cout << "ROOM  NUMBER: " << current2->room_numbers<< "             ";            
         
		    cout << "PER ROOM PRICE: "<< current2->room_prices;
         
		    cout << std::endl;
         
		    current2= current2->next;
        }
    }
   
   
    int RoomsBooking(string roomNo, string r)
    {
    Hotel* current2 = head2;
        while (current2 != NULL && current2->room_numbers != roomNo) {
            current2 = current2->next;
        }
        if (current2 == NULL) {
            cout << "ROOMS NOT FOUND!" << endl;
            return current2->countrooms;
        }
        else
        {
        if (current2->countrooms == current2->rooms)
        {
        cout << "SORRY THE ROOMS ARE FULL \n\n";
        return current2->countrooms;
}
        current2->Room[current2->countrooms++] = r;
        cout << "ROOM BOOKED!!\n\n";
        return current2->countrooms;
}
}

       void displayHotelReservationDetails(string roomNo){

    Hotel* current2 = head2;
    while (current2 != NULL && current2->room_numbers != roomNo) {
            current2 = current2->next;
        }
        if (current2 == NULL) {
            cout << "Room not found" << endl;
            return;
        }
        else
        {
        cout << "HOTEL NAME: " << current2->hotel_name << "|  ";
        
		cout << "AVALABILITY OF ROOM  " << current2->rooms << "|  ";
        
		cout << "Room Number: " << current2->room_numbers << "|  ";
        
		cout << "ROOMS : " << current2->rooms << "|  ";
        
		cout << "TOTAL ROOM RESERVED: "<<current2->countrooms<< "|  ";
        
		cout << "TOTAL AMOUNT THEY GET YET : "<< current2->room_prices * current2->countrooms << " PKR \n ";
        
		cout << "REMAINING ROOMS:" << current2->rooms - current2->countrooms<< "\n";
        
		cout << "TOP CUSTOMER: "<<endl;
        
		int i = 0 , count;
        if (current2->countrooms < 10)
        count = current2->countrooms;
        else
        count = 10;
        while (i != count)
        {
        cout << current2->Room[i];
        cout<<endl;
        i+=1;
}
}
}
   private:
   Hotel* head2;

};

// helper function
     string makecapital(string str)
{
    for(int i=0;i<str.length();i++)
    {
        if(str[i]>96&&str[i]<123)
            str[i]=str[i]-32;
    }
    return str;
}

int main() {

  TravelPlanner travelPlanner;
  ofstream flight("flight.txt",std::ios_base::app), room("room.txt", std::ios_base::app);
	//create.close();
	system("CLS");
	cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
    system("Color 6");
    cout<<"  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"                                                          'W E L C O M E    T O      T R A V E L   P L A N N E R!'                                                  "<<endl;
 
    cout<<endl;
    cout<<endl;
	cout<<"  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"  ------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    Sleep(1000);
    system("CLS");
    system("Color 3");
    cout<<endl;
    cout<<"                                                          'W E L C O M E    T O      T R A V E L   P L A N N E R!'                                                  "<<endl;
 
    cout<<endl;
    cout<<endl;
    cout<<"========================================================================================================================================================================"<<endl;
    
    cout<<"                                                          *   O U R     F L I G H T    S C H E D U L E   *                                    "<<endl;
    cout<<"========================================================================================================================================================================"<<endl;
    
	travelPlanner.addFlight("ABC123", "Islamabad", "Karachi ", 100, 45000.0);
    
	travelPlanner.addFlight("DEF456", "Sialkot  ", "Lahore  ", 150, 23000.0);
    
	travelPlanner.addFlight("GHI789", "Multan   ", "Karachi ", 200, 21000.0);
    
	travelPlanner.addFlight("JKL167", "Peshawar ", "Chitral ", 150, 15000.0);
    
	travelPlanner.addFlight("MNO496", "Gilgit   ", "Lahore  ", 200, 12000.0);
    
	travelPlanner.addFlight("PQR968", "Multan   ", "Peshawar", 100, 13000.0);
    
	travelPlanner.addFlight("STU796", "Quetta   ", "Lahore  ", 150, 18000.0);
    
	travelPlanner.addFlight("VWX005", "Karachi  ", "Gilgit  ", 100, 27000.0);
    
	travelPlanner.addFlight("YZA007", "Gawadar  ", "Karachi ", 1, 14000.0);
    
	travelPlanner.displayFlights();
	
	cout<<"========================================================================================================================================================================="<<endl;
   	
	cout<< "\n\n\n PRESS KEY TO BOOK A FLIGHT !!\n";
   	getch();
   	int j = 1, numm, seat; 
   	string namee, f_n;
   	while(j == 1)
   	{
   	cout<<"1: BOOK A FLIGHT \n";
  
   	cout<<"2: KNOW THE DETAILS OF A FLIGHT\n";
  
   	cout<<"3: Update Flight Details\n";
  
   	cin >> numm;
   	if (numm == 1)
   	{
   	cout<<"ENTER YOUR NAME:\n";
    fflush(stdin);
    getline(cin, namee);
    fflush(stdout);
   
    cout << "ENTER FLIGHT NUMBER TO BOOK YOUR FLIGHT\n";
    cin>>f_n;
   
    fflush(stdout); 
    f_n = makecapital(f_n); // just to sure that it is in right form
	seat = travelPlanner.BookAFlightForPerson(f_n, namee);	
	flight<<f_n<<"\t"<<namee<<"\t"<<seat<<endl; 
	}
	else if (numm == 2)
	{
		cout<<"\nENTER FLIGHT NUMBER TO KNOW THE DETAILS:\n";
		cin>>f_n;
   	 	f_n = makecapital(f_n);
	 travelPlanner.displayFlightDetails(f_n);
	}
	else
	{
		travelPlanner.updateFlightDetails();
	}
	cout<<"\nWANTS TO CHOOSE AGAIN ? IF YES PRESS 1 ELSE PRESS 0\n";
	cin >> j; 
	}
	flight.close();
//	return 0;
   Reservation  reservation ;
   
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"                                                          *   O U R       H O T E L     S C H E D U L E   *                                    "<<endl;
    cout<<"========================================================================================================================================================================"<<endl;
    
	reservation.addHotel("City hotel  ","1", "a1010",  25000.0,1);
    
	reservation.addHotel("Lily hotel  ","2", "b2020",  23000.0,2);
    
	reservation.addHotel("Mark hotel  ","4", "c3030",  21000.0,4);
    
	reservation.addHotel("Mini hotel  ","4", "d4040",  25000.0,4);
    
	reservation.addHotel("Regent hotel","7", "e5050",  28000.0,7);
    
	reservation.addHotel("Bany hotel  ","9", "f6060",  23000.0,9);
    
	reservation.addHotel("Cave hotel  ","3", "g7070",  28000.0,3);
    
	reservation.addHotel("Reso hotel  ","1", "h8080",  27000.0,1);
    
	reservation.addHotel("Plaxa hotel ","4", "i9090",  24000.0,4);
      
    reservation.displayHotel();
  
   cout<<"========================================================================================================================================================================="<<endl;
   
    cout<< "\n\n\n PRESS KEY TO BOOK A HOTEL !!\n";
    
	getch();
    int i = 1, num;
    string name, room_n;
    while(i == 1)
    {
    cout<<"1: BOOK A ROOM \n";
    cout<<"2: KNOW THE DETAILS OF A ROOM\n";
    cin >> num;
    if (num == 1)
    {
    cout<<"ENTER CUSTOMER NAME:\n";
    fflush(stdin);
    getline(cin, name);
    fflush(stdout);
    int n;
    cout<<"How many rooms you want to book?\n ";
    cin>>n;
    for(int i=0;i<n;i++){
    cout << "ENTER ROOM NUMBER TO BOOK YOUR ROOM\n";
    cin>>room_n;
    fflush(stdout);
 	int r = reservation.RoomsBooking(room_n, name);
 	room<<"HOTEL'S ROOM NUMBER: "<<room_n<<" RECENT PASSENGER BOOKED : "<<name<<" ROOMS RESERVED: "<<r<<endl; 
}
	}
else
{
cout<<"\nENTER ROOM NUMBER TO KNOW THE DETAILS:\n";

cin>>room_n;

 reservation.displayHotelReservationDetails(room_n);
}
cout<<"WANTS TO CHOOSE AGAIN ? IF YES PRESS 1 ELSE PRESS 0\n";

cin >> i;
}
room.close();

return 0;
}
