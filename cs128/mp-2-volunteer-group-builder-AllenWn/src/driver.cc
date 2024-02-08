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

void ParseArguments(int argc, char* argv[], std::string& input_file_name, std::string& output_file_name, int& number_of_volunteers) {
    if (argc != 4) {
        std::cerr <<  "Usage: " << argv[0] << " <input_file> <number_of_volunteers> <output_file>\n";
        exit(1);
    }
    input_file_name = argv[1];
    number_of_volunteers = std::stoi(argv[2]);
    output_file_name = argv[3];
}

void ReadVolunteers(const std::string& file_name, std::vector<Volunteer>& volunteers) {
    std::ifstream input_file(file_name);
    std::string name;
    int building_experience = 0;
    int physical_stamina = 0;
    bool returning = false;
    while (input_file >> name >> building_experience >> physical_stamina >> returning) {
        volunteers.emplace_back(name, building_experience, physical_stamina, returning);
    }
    input_file.close();
}

void InitializeGroups(const std::vector<Volunteer>& volunteers, std::vector<Group>& groups, int number_of_volunteers) {
    int number_of_groups = number_of_volunteers / kSizeGroups;
    groups.resize(number_of_groups);
    for (int i = 0; i < number_of_volunteers; ++i) {
        groups[i / kSizeGroups].AddVolunteer(volunteers[i]);
    }
}

int main(int argc, char* argv[]) {
 srand(time(nullptr));
    std::string input_file_name, output_file_name;
    int number_of_volunteers = 0;
    ParseArguments(argc, argv, input_file_name, output_file_name, number_of_volunteers);
    std::vector<Volunteer> volunteers;
    ReadVolunteers(input_file_name, volunteers);
    std::vector<Group> groups;
    InitializeGroups(volunteers, groups, number_of_volunteers);
    int number_of_group = number_of_volunteers / kSizeGroups;
    bool all_groups_valid = false; 
    unsigned int iterations = 0;
    while (! all_groups_valid && iterations < kMaxIterations) {
      all_groups_valid = true;
      for (auto& group : groups) {
          if (group.GetAvgBuildingExp() < kMinAvgBuildingExp || group.GetAvgStamina() < kMinAvgStamina || group.GetReturningMembers() < kMinReturning) {
            int rd_group_index1 = rand() % number_of_group;
            int rd_group_index2 = rand() % number_of_group;
            while (rd_group_index1 == rd_group_index2) { rd_group_index2 = rand() % number_of_group; }
            Volunteer rd_volunteer1 = groups[rd_group_index1].GetRandomVolunteer();
            Volunteer rd_volunteer2 = groups[rd_group_index2].GetRandomVolunteer();
            groups[rd_group_index1].RemoveVolunteer(rd_volunteer1);
            groups[rd_group_index2].RemoveVolunteer(rd_volunteer2);
            groups[rd_group_index1].AddVolunteer(rd_volunteer2);
            groups[rd_group_index2].AddVolunteer(rd_volunteer1);
            iterations++;
          }
      }
        for (auto& group : groups){
          if (group.GetAvgBuildingExp() < kMinAvgBuildingExp || group.GetAvgStamina() < kMinAvgStamina || group.GetReturningMembers() < kMinReturning) {
            all_groups_valid = false; }
        }
    }
    if (all_groups_valid) { 
        std::ofstream output_file(output_file_name); 
        for (const auto& group : groups) {
            output_file << group; 
        } output_file.close(); 
    } else { std::cout << "No groups found\n"; }
    return 0; 
}

