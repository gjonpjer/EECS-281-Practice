#include <vector>
#include <queue>

struct Applicant {
	std::string uniqname;
	int32_t application_id;
};
// Assume this is already implemented for the sake of this problem
// Returns a number in the range [0, 100] that identifies a person's level of
// qualification
int32_t get_qualifications(const Applicant& applicant);

struct QualificationData { 
    Applicant applicant; 
    int32_t qualification; 
  
    QualificationData(const Applicant& applicant_in) :applicant(applicant_in) {
      qualification = get_qualifications(applicant); 
    }  
};

Struct ApplicantCompare() { 

    bool operator() (const QualificationData& lhs, const QualificationData& rhs) { 
        if (lhs.qualiflication == rhs.qualification) { 
            return lhs.applicant.application_id < rhs.applicant.application_id; 
        }
        return lhs.qualification > rhs.qualification; 
    }
};
// Implement this function to solve the question
std::vector<Applicant> hire_staff(const std::vector<Applicant>& applicants,
                                  int32_t k) {
	std::vector<Applicant> future_hires;
	future_hires.reserve(k);
	// We need a min heap priority queue. Fill the queue with first k
	// people, and if there's a case in which an applicant has the same score,
	// then check their id
	std::priority_queue<QualificationData, std::vector<QualificationData>, ApplicantCompare> pq; 
	for(const auto& applicant : applicants) { 
	    pq.emplace(applicant);
	    if(pq.size() > k) { 
	        pq.pop();
	    }
	}
	
	while(!pq.empty())  {
	    future_hires.push_back(pq.top().applicant);
	    pq.pop(); 
	}
	return future_hires;
}


