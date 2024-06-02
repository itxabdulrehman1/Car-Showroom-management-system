#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <windows.h> // For system("cls")

using namespace std;

class Structure {
protected:
    string name;
    string address;
    string phone;
    string email;
    string age;
    string salary;
    string occupation;
    string grade;
    string car;
    bool chkCar;

public:
   
};

class Car : public Structure {
private:
    string brand;
    string model;
    string color;
    string registration;
    int quantity;
    string engine;
    int year;
    string company;

public:
    

    void addCar() {
    	
        ofstream file("car_info.txt", ios::out |ios::app);
        
		if (file.is_open()) {
        
		    file << brand << "," << model << "," << color << "," << registration << "," << quantity << "," << engine << "," << year << "," << company << endl;
        
		    file.close();
        
		    cout << "\n******** Car data added successfully! ********\n" << endl;
        
		} else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        
		}
    }

    void displayCars() {
        
		ifstream file("car_info.txt");
        
		if (file.is_open()) {
        
		    string line;
        
		    cout << "\n================= Car Information =================" << endl;
        
		    cout << setw(10) << "Brand" << setw(10) << "Model" << setw(10) << "Color" << setw(15) << "Registration" << setw(10) << "Quantity" << setw(10) << "Engine" << setw(5) << "Year" << setw(10) << "Company" << endl;
        
		    cout << "==================================================" << endl;
        
		    while (getline(file, line)) {
                cout << line << endl;
            }
        
		    file.close();
        } else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        
		}
    }

    void updateCar() {
        
		ifstream file("car_info.txt");
        
		ofstream temp("temp.txt");
        
		string line, modelToUpdate, newColor;

        if (file.is_open()) {
        
		    cout << "Enter the model of the car to update: ";
        
		    getline(cin, modelToUpdate);

            while (getline(file, line)) {
        
		        if (line.find(modelToUpdate) != string::npos) {
                    cout << "Enter new color: ";
        
		            getline(cin, newColor);
        
		            temp << line.substr(0, line.find_last_of(',')) << "," << newColor << endl;
                } else {
                    temp << line << endl;
                }
            }
            file.close();
            temp.close();
            remove("car_info.txt");
        
		    rename("temp.txt", "car_info.txt");
        
		    cout << "\n******** Car data updated successfully! ********\n" << endl;
        }
		 else {
            
			cout << "\n******** Unable to open file ********\n" << endl;
        
		}
    }

    void deleteCar() {
        ifstream file("car_info.txt");
        ofstream temp("temp.txt");
        string line, modelToDelete;

        if (file.is_open()) {
        
		    cout << "Enter the model of the car to delete: ";
        
		    getline(cin, modelToDelete);

            while (getline(file, line)) {
        
		        if (line.find(modelToDelete) == string::npos) {
        
		            temp << line << endl;
                }
            }
            file.close();
            temp.close();
        
		    remove("car_info.txt");
        
		    rename("temp.txt", "car_info.txt");
        
		    cout << "\n******** Car data deleted successfully! ********\n" << endl;
        }
		 else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        
		}
    }

    void searchCarByModel(const string& query) {
        
		ifstream file("car_info.txt");
        
		if (file.is_open()) {
        
		    string line;
        
		    bool found = false;
        
		    while (getline(file, line)) {
        
		        if (line.find(query) != string::npos) {
        
		            cout << line << endl;
        
		            found = true;
                }
            }
        
		    if (!found) {
                cout << "\n******** Car not found ********\n" << endl;
            }
        
		    file.close();
        } else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        }
    }
    
     bool isCarAvailable( string carModel) {
        
		ifstream file("car_info.txt");
        
		if (file.is_open()) {
        
		    string line;
        
		    while (getline(file, line)) {
        
		        if (line.find(carModel) != string::npos) {
        
		            file.close();
        
		            return true; // Car found
                }
            }
            file.close();
        }
        
		return false; // Car not found
    }



    void buyCar() {
        
		string customerName, address, mobileNumber, email, insurance, carModel;

        cout << "Enter car model to purchase: ";
        getline(cin, carModel);

        if (!isCarAvailable(carModel)) {
        
		    cout << "\n******** Car not available for purchase ********\n" << endl;
        
		    return;
        
		}

        cout << "Enter customer name: ";
        
		getline(cin, customerName);

        cout << "Enter address: ";
        
		getline(cin, address);

        cout << "Enter mobile number: ";
        
		getline(cin, mobileNumber);

        cout << "Enter email: ";
        
		getline(cin, email);

        cout << "Enter insurance: ";
        
		getline(cin, insurance);

        // purchasing ka lia aik alhda file use ki ha yahan
        ofstream purchaseRecord("purchase_record.txt", ios::app);
        
        
		if (purchaseRecord.is_open()) {
        
		    purchaseRecord << "Customer Name: " << customerName << endl;
        
		    purchaseRecord << "Address: " << address << endl;
        
		    purchaseRecord << "Mobile Number: " << mobileNumber << endl;
        
		    purchaseRecord << "Email: " << email << endl;
        
		    purchaseRecord << "Insurance: " << insurance << endl;
        
		    purchaseRecord << "Purchased Car Model: " << carModel << endl;
        
		    purchaseRecord << endl;
        
		    purchaseRecord.close();
        
		    cout << "\n******** Car purchased successfully! ********\n" << endl;
        
		} else {
        
		    cout << "\n******** Unable to open purchase record file ********\n" << endl;
        }
    }



    void rentCar() {
        string customerName, address, mobileNumber, email, insurance, rentalDuration, carModel;

        cout << "Enter car model to rent: ";
        
		getline(cin, carModel);

        if (!isCarAvailable(carModel)) {
        
		    cout << "\n******** Car not available for rent ********\n" << endl;
        
		    return;
       
	    }

        cout << "Enter customer name: ";
        getline(cin, customerName);


        cout << "Enter address: ";
        getline(cin, address);


        cout << "Enter mobile number: ";
        getline(cin, mobileNumber);


        cout << "Enter email: ";
        getline(cin, email);


        cout << "Enter insurance: ";
        getline(cin, insurance);


        cout << "Enter rental duration (e.g., days, weeks, months): ";
        getline(cin, rentalDuration);

        // rent cars ka lia aik alhda file use hoi ha
        ofstream rentalRecord("rental_record.txt", ios::app);

        if (rentalRecord.is_open()) {

            rentalRecord << "Customer Name: " << customerName << endl;

            rentalRecord << "Address: " << address << endl;

            rentalRecord << "Mobile Number: " << mobileNumber << endl;

            rentalRecord << "Email: " << email << endl;

            rentalRecord << "Insurance: " << insurance << endl;

            rentalRecord << "Rental Duration: " << rentalDuration << endl;

            rentalRecord << "Rented Car Model: " << carModel << endl;

            rentalRecord << endl;

            rentalRecord.close();

            cout << "\n******** Car rented successfully! ********\n" << endl;

        } else {

            cout << "\n******** Unable to open rental record file ********\n" << endl;
        }
    }
    
    
};

class Employee : public Car {
public:
	void calculate_salary()
{
	int choice;
	int hours;
	int payRate;
	int total;
	
	cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\n";
        cout << "\t\t _______________________________________________________________________________________\n";
        cout << "\t\t|                                           		                                |\n";
        cout << "\t\t|                                           		                                |\n";
        cout << "\t\t|                                           		                                |\n";
        cout << "\t\t|                                           		                                |\n";
        cout << "\t\t|                    ---------------------------------------------                      |\n";
        cout << "\t\t|                    *********************************************                      |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                                       WELCOME TO                                      |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                              EMPLOYEE MANAGEMENT SYSTEM                               |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                     ********************************************                      |\n";
        cout << "\t\t|                    ---------------------------------------------                      |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|_______________________________________________________________________________________|\n";
        cout << "\n\n\n\nLoading Please Wait....";

        Sleep(4000);
        system("cls");
	
	


	
	m:
	   cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  EMPLOYEE MANAGEMENT SYSTEM \n\n";
                            cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
                            cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
                            cout << "\t\t\t\t\t\t|                                                                 |\n";
                            cout << "\t\t\t\t\t\t|             1.  -> CALCULATE HOURLY SALARY                      |\n";
                            cout << "\t\t\t\t\t\t|             2.  -> CALCULATE WEEKLY SALARY                      |\n";
                            cout << "\t\t\t\t\t\t|             3.  -> CALCULATE MONTHLY SALARY                     |\n";
                            cout << "\t\t\t\t\t\t|             4.  -> CALCULATE YEARLY SALARY                      |\n";
                            cout << "\t\t\t\t\t\t|             5.  -> EXIT                                         |\n";
                            cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
                            cout << "Enter your choice: ";
	
	
	cin>>choice;
	
	switch(choice)
	{
		case 1:
			{
				cout<<"Enter the number of hours worked  :			";
				cin>>hours;
				cout<<"Enter the Hourly pay rate         :			";
				cin>>payRate;
				cout<<endl<<endl;
				total=hours*payRate;
				
				cout<<"Your salary is   : 			"<<total;
				goto m;
				break;
			}
			
		case 2:
			{
				cout<<"Enter the number of hours worked per day :			";
				cin>>hours;
				cout<<"Enter the Hourly pay rate         :			";
				cin>>payRate;
				cout<<endl<<endl;
				total=hours*payRate*7;
				
				cout<<"Your Weekly salary is   : 			"<<total;
				goto m;
				break;
			}
			
		case 3:
			{
				cout<<"Enter the number of hours worked  per day:			";
				cin>>hours;
				cout<<"Enter the Hourly pay rate         :			";
				cin>>payRate;
				cout<<endl<<endl;
				total=hours*payRate*30;
				
				cout<<"Your Monthly salary is   : 			"<<total;
				goto m;
				break;
			}
			
		case 4:
			{
				cout<<"Enter the number of hours worked per day :			";
				cin>>hours;
				cout<<"Enter the Hourly pay rate         :			";
				cin>>payRate;
				cout<<endl<<endl;
				total=hours*payRate*365;
				
				cout<<"Your Yearly salary is   : 			"<<total;
				goto m;
				break;
			}	
					
		case 5:
			{
				return;
			}
			
		default:
			{
				cout<<"Invalid choice  !";
				goto m;	
			}	
			
	}
}

    

    void addEmployee() {
        
		ofstream file("employee_info.txt", ios::app);
        
		if (file.is_open()) {
        
		    file << name << "," << address << "," << phone << "," << email <<","<<age<<","<<salary<<","<<occupation<<","<<grade<< endl;
        
		    file.close();
        
		    cout << "\n******** Employee data added successfully! ********\n" << endl;
        
		} else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        
		}
    }

    void displayEmployees() {
        
		ifstream file("employee_info.txt");
       
	    if (file.is_open()) {
	    	
            string line;
        
		    cout << "\n=============== Employee Information ==============" << endl;
        
		    cout << setw(10) << "Name" << setw(20) << "Address" << setw(15) << "Phone" << setw(25) << "Email" << endl;
        
		    cout << "==================================================" << endl;
        
		    while (getline(file, line)) {
        
		        cout << line << endl;
            }
        
		    file.close();
        }
		 else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        }
    }

    void updateEmployee() {
        
		ifstream file("employee_info.txt");
        
		ofstream temp("temp.txt");
        
		string line, nameToUpdate, newAddress, newPhone, newEmail , newAge , newSalary ;

        if (file.is_open()) {
        
		    cout << "Enter the name of the employee to update: ";
        
		    getline(cin, nameToUpdate);

            while (getline(file, line)) {
        
		        if (line.find(nameToUpdate) != string::npos) {
        
		            cout << "Enter new address: ";
        
		            getline(cin, newAddress);
        
		            cout << "Enter new phone number: ";
        
		            getline(cin, newPhone);
        
		            cout << "Enter new email: ";
        
		            getline(cin, newEmail);

                    temp << nameToUpdate << "," << newAddress << "," << newPhone << "," << newEmail<< endl;
                }
				 else {
                
				    temp << line << endl;
                }
            }
            file.close();
            
			temp.close();
            
			remove("employee_info.txt");
            
			rename("temp.txt", "employee_info.txt");
            
			cout << "\n******** Employee data updated successfully! ********\n" << endl;
        } 
		else {
            
			cout << "\n******** Unable to open file ********\n" << endl;
        
		}
    }

    void deleteEmployee() {
        
		ifstream file("employee_info.txt");
        
		ofstream temp("temp.txt");
        
		string line, nameToDelete;

        if (file.is_open()) {

            cout << "Enter the name of the employee to delete: ";

            getline(cin, nameToDelete);

            while (getline(file, line)) {

                if (line.find(nameToDelete) == string::npos) {

                    temp << line << endl;
                }
            }


            file.close();

            temp.close();

            remove("employee_info.txt");

            rename("temp.txt", "employee_info.txt");

            cout << "\n******** Employee data deleted successfully! ********\n" << endl;
        } 
		else {

            cout << "\n******** Unable to open file ********\n" << endl;
        }
    }

    void searchEmployeeByName(const string& query) {
        
		ifstream file("employee_info.txt");
        
		if (file.is_open()) {
        
		    string line;
        
		    bool found = false;
        
		    while (getline(file, line)) {
        
		        if (line.find(query) != string::npos) {
        
		            cout << line << endl;
        
		            found = true;
                }
            }
        
		    if (!found) {
        
		        cout << "\n******** Employee not found ********\n" << endl;
        
		    }
        
		    file.close();
        }
		 else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        }
    }
};

class Customer : public Employee {
public:
    

	void menu()
	{
		
		int choice;
    
	do {
        cout << "================== Main Menu ==================" << endl;
        cout << "1. Car Section" << endl;
        cout << "2. Employee Section" << endl;
        cout << "3. Customer Section" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
    
	    cin >> choice;
    
	    cin.ignore(); // To clear the input buffer

        system("cls");

        switch (choice) {
    
	        case 1: {
                
                int carChoice;
    
	            do {
                    
					cout << "================= Car Section =================" << endl;
                    cout << "1. Add Car" << endl;
                    cout << "2. Display Cars" << endl;
                    cout << "3. Update Car" << endl;
                    cout << "4. Delete Car" << endl;
                    cout << "5. Search Car by Model" << endl;
                    cout << "6. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    
					cin >> carChoice;
                    
					cin.ignore(); // To clear the input buffer

                    system("cls");

                    switch (carChoice) {
                    
					    case 1: {
                    
					        string brand, model, color, registration, engine, company;
                    
					        int quantity, year;
                    
					        cout << "Enter brand: ";
                    
					        getline(cin, brand);
                    
					        cout << "Enter model: ";
                    
					        getline(cin, model);
                    
					        cout << "Enter color: ";
                    
					        getline(cin, color);
                    
					        cout << "Enter registration: ";
                    
					        getline(cin, registration);
                    
					        cout << "Enter quantity: ";
                    
					        cin >> quantity;
                    
					        cin.ignore();
                    
					        cout << "Enter engine: ";
                    
					        getline(cin, engine);
                    
					        cout << "Enter year: ";
                    
					        cin >> year;
                    
					        cin.ignore();
                    
					        cout << "Enter company: ";
                    
					        getline(cin, company);

					        ofstream file("car_info.txt", ios::out |ios::app);

        if (file.is_open()) {

            file << brand << "," << model << "," << color << "," << registration << "," << quantity << "," << engine << "," << year << "," << company << endl;

            file.close();

            cout << "\n******** Car data added successfully! ********\n" << endl;
        } 
		else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        
		}

                            system("cls");
        
		                    break;
                        }
                        case 2:
        
		                    displayCars();
                            break;
                        case 3:
        
		                    updateCar();
        
		                    system("cls");
                            break;
                        case 4:
        
		                    deleteCar();
        
		                    system("cls");
                            break;
                        case 5: {
        
		                    string model;
        
		                    cout << "Enter model to search: ";
        
		                    getline(cin, model);
        
		                    searchCarByModel(model);
        
		                    break;
                        }
                        case 6:
        
		                    system("cls");
        
		                    break;
        
		                default:
        
		                    cout << "Invalid choice. Please try again." << endl;
                    }
                } while (carChoice != 6);
        
		        break;
            }
            case 2: {
                
                int empChoice;
        
		        do {
		        	
                    cout << "=============== Employee Section ==============" << endl;
                    cout << "1. Add Employee" << endl;
                    cout << "2. Display Employees" << endl;
                    cout << "3. Update Employee" << endl;
                    cout << "4. Delete Employee" << endl;
                    cout << "5. Search Employee by Name" << endl;
                    cout << "6. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";
                    
					cin >> empChoice;
                    
					cin.ignore(); // To clear the input buffer

                    system("cls");

                    switch (empChoice) {
                        case 1: {
                    
					        string name, address, phone, email;
                    
					        cout << "Enter name: ";
                    
					        getline(cin, name);
                    
					        cout << "Enter address: ";
                    
					        getline(cin, address);
                    
					        cout << "Enter phone number: ";
                    
					        getline(cin, phone);
                    
					        cout << "Enter email: ";
                    
					        getline(cin, email);
					        
					        cout << "Enter age: ";
                    
					        getline(cin, age);

                    	 cout << "Enter salary ";
                    
					        getline(cin, salary); 
							
							cout << "Enter occupation ";
                    
					        getline(cin, occupation);

                    	 cout << "Enter grade ";
                    
					        getline(cin, grade);       
                            
        fstream file("employee_info.txt",ios::out| ios::app);
        
		if (file.is_open()) {
        
		    file << name << "," << address << "," << phone << "," << email << endl;
        
		    file.close();
        
		    cout << "\n******** Employee data added successfully! ********\n" << endl;
        }
		 else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;

        }


                            system("cls");

                            break;
                        }
                        case 2:

                            displayEmployees();
                            break;
                        case 3:
                            updateEmployee();

                            system("cls");
                            break;
                        case 4:
                            deleteEmployee();

                            system("cls");
                            break;
                        case 5: {
                            string name;

                            cout << "Enter name to search: ";

                            getline(cin, name);

                            searchEmployeeByName(name);
                            break;
                        }
                        case 6:

                            system("cls");
                            break;
                        default:

                            cout << "Invalid choice. Please try again." << endl;
                    }
                } while (empChoice != 6);
                break;
            }
            case 3: {
                
                int custChoice;

                do {

                    cout << "=============== Customer Section ==============" << endl;
                    cout << "1. Add Customer" << endl;
                    cout << "2. Display Customers" << endl;
                    cout << "3. Update Customer" << endl;
                    cout << "4. Delete Customer" << endl;
                    cout << "5. Search Customer by Name" << endl;
                    cout << "6. Back to Main Menu" << endl;
                    cout << "Enter your choice: ";

                    cin >> custChoice;

                    cin.ignore(); // To clear the input buffer

                    system("cls");

                    switch (custChoice) {

                        case 1: {

                            string name, address, phone, email;

                            cout << "Enter name: ";

                            getline(cin, name);

                            cout << "Enter address: ";

                            getline(cin, address);

                            cout << "Enter phone number: ";

                            getline(cin, phone);

                            cout << "Enter email: ";

                            getline(cin, email);

                            
                        ofstream file("customer_info.txt",ios::out| ios::app);


        if (file.is_open()) {

            file << name << "," << address << "," << phone << "," << email << endl;

            file.close();

            cout << "\n******** Customer data added successfully! ********\n" << endl;
        }
		 else {

            cout << "\n******** Unable to open file ********\n" << endl;
        
		}


                            system("cls");
        
		                    break;
                        }
                        case 2:
        
		                    displayCustomers();
        
		                    break;
                        case 3:
        
		                    updateCustomer();
        
		                    system("cls");
        
		                    break;
                        case 4:
                            deleteCustomer();
        
		                    system("cls");
        
		                    break;
                        case 5: {
                            string name;
        
		                    cout << "Enter name to search: ";
        
		                    getline(cin, name);
        
		                    searchCustomerByName(name);
        
		                    break;
                        }
                        case 6:
        
		                    system("cls");
        
		                    break;
                        default:
        
		                    cout << "Invalid choice. Please try again." << endl;
        
		            }
                }
                
				 while (custChoice != 6);
                
				break;
            }
            case 4:
                
				cout << "Exiting program..." << endl;
                
				break;
            default:
                
				cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);
	}


    void addCustomer() {
        
		ofstream file("customer_info.txt", ios::app);
        
		if (file.is_open()) {
        
		    file << name << "," << address << "," << phone << "," << email << endl;
        
		    file.close();
        
		    cout << "\n******** Customer data added successfully! ********\n" << endl;
        }
		 else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        }
    }

    void displayCustomers() {
       
	    ifstream file("customer_info.txt");
       
	    if (file.is_open()) {
       
	        string line;
       
	        cout << "\n=============== Customer Information ==============" << endl;
       
	        cout << setw(10) << "Name" << setw(20) << "Address" << setw(15) << "Phone" << setw(25) << "Email" << endl;
       
	        cout << "==================================================" << endl;
       
	        while (getline(file, line)) {
       
	            cout << line << endl;
            }
            file.close();
        } else {
            cout << "\n******** Unable to open file ********\n" << endl;
        }
    }

    void updateCustomer() {
       
	    ifstream file("customer_info.txt");
       
	    ofstream temp("temp.txt");
       
	    string line, nameToUpdate, newAddress, newPhone, newEmail;

        if (file.is_open()) {
       
	        cout << "Enter the name of the customer to update: ";
       
	        getline(cin, nameToUpdate);

            while (getline(file, line)) {
       
	            if (line.find(nameToUpdate) != string::npos) {
       
	                cout << "Enter new address: ";
       
	                getline(cin, newAddress);
       
	                cout << "Enter new phone number: ";
                    getline(cin, newPhone);
       
	                cout << "Enter new email: ";
                    getline(cin, newEmail);

                    temp << nameToUpdate << "," << newAddress << "," << newPhone << "," << newEmail << endl;
         
		        } else {
                    temp << line << endl;
                }
            }
            file.close();
            temp.close();
          
		    remove("customer_info.txt");
            rename("temp.txt", "customer_info.txt");
        
		    cout << "\n******** Customer data updated successfully! ********\n" << endl;
        } 
		else {
            cout << "\n******** Unable to open file ********\n" << endl;
        }
    }

    void deleteCustomer() {
        ifstream file("customer_info.txt");
        ofstream temp("temp.txt");
        
		string line, nameToDelete;

        if (file.is_open()) {
        
		    cout << "Enter the name of the customer to delete: ";
            getline(cin, nameToDelete);

            while (getline(file, line)) {
                if (line.find(nameToDelete) == string::npos) {
        
		
		            temp << line << endl;
                }
            }
            file.close();
        
		    temp.close();
        
		    remove("customer_info.txt");
            rename("temp.txt", "customer_info.txt");
        
		    cout << "\n******** Customer data deleted successfully! ********\n" << endl;
        }
		 else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        
		}
    }

    void searchCustomerByName(const string& query) {
        
		ifstream file("customer_info.txt");
        
		if (file.is_open()) {
            string line;
        
		    bool found = false;
        
		
		    while (getline(file, line)) {
        
		        if (line.find(query) != string::npos) {
        
		            cout << line << endl;
        
		            found = true;
                }
            }
        
		    if (!found) {
        
		        cout << "\n******** Customer not found ********\n" << endl;
            }
        
		    file.close();
        }
		 else {
        
		    cout << "\n******** Unable to open file ********\n" << endl;
        
		}
    }
};



class Admin : public Customer{

private:
    string username;
    string password;

    void saveCredentialsToFile();

public:
    Admin();
    void adminLogin();
    void adminRegistration();
    void adminPasswordReset();
    bool authenticate(string enteredUsername, string enteredPassword);
};

Admin::Admin() {
    username = "";
    password = "";
}

void Admin::saveCredentialsToFile() {

    ofstream file("login.txt", ios::app);

    if (file.is_open()) {

        file << username << " " << password << endl;

        file.close();

    } else {

        cout << "Error saving credentials." << endl;

    }
}

void Admin::adminLogin() {

    string enteredUsername, enteredPassword;
    cout << "Enter username: ";

    cin >> enteredUsername;

    cout << "Enter password: ";

    cin >> enteredPassword;

    ifstream file("login.txt");

    if (file.is_open()) {


        while (file >> username >> password) {


            if (authenticate(enteredUsername, enteredPassword)) {


                cout << "Login successful!" << endl;
                 menu();
                file.close();


                return;
            }
        }

        file.close();

    } else {

        cout << "Error opening login file." << endl;

    }

    cout << "Invalid username or password." << endl;

}

void Admin::adminRegistration() {

    string newUsername, newPassword;


    cout << "Enter new username: ";
    cin >> newUsername;


    cout << "Enter new password: ";
    cin >> newPassword;

    username = newUsername;
    password = newPassword;

    saveCredentialsToFile();

    cout << "Registration successful!" << endl;

}

void Admin::adminPasswordReset() {


    string enteredUsername, newPassword;


    cout << "Enter your username: ";
    cin >> enteredUsername;

    ifstream file("login.txt");
    ofstream temp("temp.txt");

    if (file.is_open() && temp.is_open()) {


        while (file >> username >> password) {


            if (username == enteredUsername) {


                cout << "Enter new password: ";
                cin >> newPassword;


                password = newPassword;
            }

            temp << username << " " << password << endl;

        }
        file.close();
        temp.close();


        remove("login.txt");
        rename("temp.txt", "login.txt");


    } else {

        cout << "Error resetting password." << endl;

    }
}

bool Admin::authenticate(string enteredUsername, string enteredPassword) {

    return username == enteredUsername && password == enteredPassword;

}

int main() {
    Employee emp;
    Car car;
    Admin admin; // Instantiate Admin object here

    int choice;
    string query;

    do {
        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\n";
        cout << "\t\t _______________________________________________________________________________________\n";
        cout << "\t\t|                                           		                                |\n";
        cout << "\t\t|                                           		                                |\n";
        cout << "\t\t|                                           		                                |\n";
        cout << "\t\t|                                           		                                |\n";
        cout << "\t\t|                    ---------------------------------------------                      |\n";
        cout << "\t\t|                    *********************************************                      |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                                       WELCOME TO                                      |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                        BAZOOKA CAR SHOWROOM MANAGEMENT SYSTEM                         |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                     ********************************************                      |\n";
        cout << "\t\t|                    ---------------------------------------------                      |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|                                                                                       |\n";
        cout << "\t\t|_______________________________________________________________________________________|\n";
        cout << "\n\n\n\nLoading Please Wait....";

        Sleep(4000);
        system("cls");

        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  CAR SHOWROOM MANAGEMENT SYSTEM \n\n";
        cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
        cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
        cout << "\t\t\t\t\t\t|             1.  -> ADMIN                                        |\n";
        cout << "\t\t\t\t\t\t|             2.  -> EMPLOYEE                                      |\n";
        cout << "\t\t\t\t\t\t|             3.  -> CUSTOMER                                      |\n";
        cout << "\t\t\t\t\t\t|             4.  -> Exit the Program                              |\n";
        cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";

        cin >> choice;

        switch (choice) {
            case 1:
                system("cls");
                {
                    string adminPassword;

                    cout << "Enter admin password: ";
                    cin >> adminPassword;

                    if (adminPassword == "bazoka") {
                        system("cls");
                        char adminChoice;

                        do {
                            cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  CAR SHOWROOM MANAGEMENT SYSTEM \n\n";
                            cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
                            cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
                            cout << "\t\t\t\t\t\t|                                                                 |\n";
                            cout << "\t\t\t\t\t\t|             A.  -> ADMIN LOGIN                                  |\n";
                            cout << "\t\t\t\t\t\t|             B.  -> ADMIN REGISTRATION                           |\n";
                            cout << "\t\t\t\t\t\t|             C.  -> ADMIN PASSWORD RESET                         |\n";
                            cout << "\t\t\t\t\t\t|             X.  -> Exit ADMIN                                   |\n";
                            cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
                            cout << "Enter your choice: ";
                            cin >> adminChoice;

                            switch (adminChoice) {
                                case 'A':
                                    system("cls");
                                    admin.adminLogin();
                                    break;
                                case 'B':
                                    system("cls");
                                    admin.adminRegistration();
                                    break;
                                case 'C':
                                    system("cls");
                                    admin.adminPasswordReset();
                                    break;
                                case 'X':
                                    system("cls");
                                    cout << "Exiting Admin Panel..." << endl;
                                    break;
                                default:
                                    cout << "Invalid choice. Please try again." << endl;
                            }
                        } while (adminChoice != 'X');
                    } else {
                        cout << "Incorrect admin password. Exiting..." << endl;
                    }
                }
                break;

            case 2:
                system("cls");
                emp.calculate_salary();
                break;

            case 3:
                system("cls");
                {
                    int choice3;
                    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t  CUSTOMER MANAGEMENT SYSTEM \n\n";
                    cout << "\n\n\t\t\t\t\t\tPlease,  Choose from the following Options: \n\n";
                    cout << "\t\t\t\t\t\t _________________________________________________________________ \n";
                    cout << "\t\t\t\t\t\t|                                                                 |\n";
                    cout << "\t\t\t\t\t\t|             1.  -> DISPLAY ALL CARS                             |\n";
                    cout << "\t\t\t\t\t\t|             2.  -> SEARCH CAR BY MODEL                          |\n";
                    cout << "\t\t\t\t\t\t|             3.  -> BUY OR RENT A CAR                            |\n";
                    cout << "\t\t\t\t\t\t|             4.  -> EXIT                                         |\n";
                    cout << "\t\t\t\t\t\t|_________________________________________________________________|\n\n";
                    cout << "Enter your choice: ";
                    cin >> choice3;

                    switch (choice3) {
                        case 1:
                            car.displayCars();
                            break;
                        case 2:
                            cout << "Enter the model of car: ";
                            cin >> query;
                            car.searchCarByModel(query);
                            break;
                        case 3:
                            int choice4;
                            do {
                                cout << "1. Buy a car\n";
                                cout << "2. Rent a car\n";
                                cout << "3. Exit\n";
                                cout << "Enter your choice: ";
                                cin >> choice4;
                                cin.ignore(); // Clear the input buffer

                                string carModel;
                                bool available;

                                switch (choice4) {
                                    case 1:
                                        cout << "Enter car model to purchase: ";
                                        getline(cin, carModel);
                                        available = car.isCarAvailable(carModel);
                                        if (available)
                                            car.buyCar();
                                        else
                                            cout << "Car not available for purchase.\n";
                                        break;
                                    case 2:
                                        cout << "Enter car model to rent: ";
                                        getline(cin, carModel);
                                        available = car.isCarAvailable(carModel);
                                        if (available)
                                            car.rentCar();
                                        else
                                            cout << "Car not available for rent.\n";
                                        break;
                                    case 3:
                                        cout << "Exiting program.\n";
                                        break;
                                    default:
                                        cout << "Invalid choice. Please enter a valid option.\n";
                                }
                            } while (choice4 != 3);
                            break;
                        case 4:
                            cout << "Exiting Customer Management System..." << endl;
                            break;
                        default:
                            cout << "Invalid choice. Please try again." << endl;
                    }
                }
                break;

            case 4:
                system("cls");
                cout << "Exiting..." << endl;
                break;

            default:
                system("cls");
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}


