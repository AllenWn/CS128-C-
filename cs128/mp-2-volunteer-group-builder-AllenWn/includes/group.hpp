#ifndef GROUP_HPP
#define GROUP_HPP

#include <ostream>
#include "volunteer.hpp"
#include <string>
#include <vector>

class Group {
public:
  void AddVolunteer(const Volunteer& vol);
  
  void RemoveVolunteer(const Volunteer& vol);

  double GetAvgBuildingExp() const;

  int GetReturningMembers() const;

  double GetAvgStamina() const;

  friend std::ostream& operator<<(std::ostream& os, const Group& g_in);

  Volunteer& GetRandomVolunteer();

private:
  std::vector<Volunteer> volunteers_;
};

std::ostream& operator<<(std::ostream& os, const Group& g_in);

#endif
