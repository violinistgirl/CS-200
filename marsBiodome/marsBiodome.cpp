#include <iostream>
#include <string>
using namespace std;

int main()
{

	bool done = false;
	const int foodConsumed_PerPersonPerDay = 2;
	const int oxygenCreated_PerDay = 5;
	const int wasteCreated_PerPersonPerDay = 3;
	const int oxygenUsed_PerPersonPerDay = 2;
	int foodGrown_PerDay, cleanup_PerPersonPerDay, foodCount, wasteCount, oxygenCount, peopleCount, missionLength;
	string teamName;

	while (done != true){
		cout << "---------------------" << endl;
		cout << "MARS COLONY MAIN MENU\n" << endl;
		cout << "1. Set Mission Parameters \n2. Run Simulation \n3. Quit" << endl;
		cout << "---------------------" << endl;
		cout << "Choice >> ";
		int choice;
		cin >> choice;

		if (choice == 1){
			cout << "\nA. Food grown per day................ ";
			cin >> foodGrown_PerDay;
			cout << "B. Cleanup per person per day........ ";
			cin >> cleanup_PerPersonPerDay;
			cout << "C. Starting units of food............ ";
			cin >> foodCount;
			cout << "D. Mission length - in days.......... ";
			cin >> missionLength;
			cout << "E. People on the mission............. ";
			cin >> peopleCount;
			cout << "F. Team name......................... ";
			cin >> teamName;

			// Test code
			/*cout << "foodGrown_PerDay: " << foodGrown_PerDay << endl;
			cout << "cleanup_PerPersonPerDay: " << cleanup_PerPersonPerDay << endl;
			cout << "foodCount: " << foodCount << endl;
			cout << "missionLength: " << missionLength << endl;
			cout << "peopleCount: " << peopleCount << endl;
			cout << "teamName: " << teamName << endl;*/

		}
		else if (choice == 2){
			int day = 1;
			oxygenCount = 100, wasteCount = 0;
			bool missionSuccess = true;

			cout << "Running Simulation" << endl;
			cout << "---------------------\n" << endl;
			while (day <= missionLength && missionSuccess != false){


				cout << "Day " << day << " of " << missionLength << endl << endl;

				cout << foodGrown_PerDay << " units of food grown" << endl;
				cout << foodConsumed_PerPersonPerDay << " units of food consumed" << endl;
				foodCount += foodGrown_PerDay;
				foodCount -= foodConsumed_PerPersonPerDay * peopleCount;
				cout << wasteCreated_PerPersonPerDay * peopleCount << " units of waste created" << endl;
				cout << cleanup_PerPersonPerDay * peopleCount << " units of waste cleaned up" << endl;
				wasteCount += wasteCreated_PerPersonPerDay * peopleCount;
				wasteCount -= cleanup_PerPersonPerDay * peopleCount;
				cout << oxygenCreated_PerDay << " units of oxygen created" << endl;
				cout << oxygenUsed_PerPersonPerDay  * peopleCount << " units of oxygen used" << endl;
				oxygenCount += oxygenCreated_PerDay;
				oxygenCount -= oxygenUsed_PerPersonPerDay * peopleCount;

				cout << "Status: " << foodCount << " food, " << wasteCount << " waste, " << oxygenCount << " oxygen" << endl;
				cout << "---------------------" << endl;


				if (foodCount < 0) {
					cout << "MISSION FAILED: Starvation." << endl;
					missionSuccess = false;
				}
				if (wasteCount > 20) {
					cout << "MISSION FAILED: Waste overflow." << endl;
					missionSuccess = false;
				}
				if (oxygenCount < 0) {
					cout << "MISSION FAILED: Suffocation." << endl;
					missionSuccess = false;
				}

				day++;
			}
			cout << "Mission outcome: ";
			if (missionSuccess == true)
				cout << "SUCCESS!\n" << endl;
			else
				cout << "FAILURE. Try again!\n" << endl;

		}
		else if (choice == 3){
			done = true;
		}
	}
}