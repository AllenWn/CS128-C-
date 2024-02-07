#include <ctime>
#include <fstream>
#include <iostream>
#include <utility> 
#include <cstdlib>
#include <string>
#include <vector>
#include <cassert>
#include <fstream>
#include <ostream>
#include "constants.hpp"
#include "group.hpp"



int main(int argc, char* argv[]) {
  srand(time(nullptr));
  if (argc != 4) {
    std::cerr <<  "Usage: " << argv[0] << " <input_file> <number_of_volunteers> <output_file>\n";
    return 1;
  }

  std::string inputFileName = argv[1]; 
  int numberOfVolunteers = std::stoi(argv[2]); 
  int numberOfGroup = numberOfVolunteers / kSizeGroups;
  std::string outputFileName = argv[3];
  
  std::ifstream inputFile(inputFileName); 
  std::vector<Volunteer> volunteers; 
  std::string name;
  int building_experience, physical_stamina; 
  bool returning;

   while (inputFile >> name >> building_experience >> physical_stamina >> returning) {
        volunteers.emplace_back(name, building_experience, physical_stamina, returning); 
    }
    inputFile.close();

    std::vector<Group> groups(numberOfVolunteers / kSizeGroups); 
    for (int i = 0; i < numberOfVolunteers; ++i) {
        groups[i / kSizeGroups].AddVolunteer(volunteers[i]); 
    }

    bool allGroupsValid = false; 
    unsigned int iterations = 0;
    while (! allGroupsValid && iterations < kMaxIterations) {
      for (auto& group : groups) {
          
          int rdGroupIndex1 = rand() % numberOfGroup;
          int rdGroupIndex2 = rand() % numberOfGroup;
          while (rdGroupIndex1 == rdGroupIndex2) {
            rdGroupIndex2 = rand() % numberOfGroup;
          }

          Volunteer rdVolunteerIndex1 = groups[rdGroupIndex1].GetRandomVolunteer();
          Volunteer rdVolunteerIndex2 = groups[rdGroupIndex2].GetRandomVolunteer();

          groups[rdGroupIndex1].RemoveVolunteer(rdVolunteerIndex1);
          groups[rdGroupIndex2].RemoveVolunteer(rdVolunteerIndex2);

          groups[rdGroupIndex1].AddVolunteer(rdVolunteerIndex2);
          groups[rdGroupIndex2].AddVolunteer(rdVolunteerIndex1);

          iterations++;

          if (group.GetAvgBuildingExp() >= kMinAvgBuildingExp && group.GetAvgStamina() >= kMinAvgStamina 
          && group.GetReturningMembers() >= kMinReturning) {
            allGroupsValid = true;
          }

      }
    }

    if (allGroupsValid) { 
        std::ofstream outputFile(outputFileName); 
        for (const auto& group : groups) {
            outputFile << group; 
        }
        outputFile.close(); 
    } else {
        std::cout << "No groups found\n"; 
    }

    return 0; 

}

