class EmployeeInformationSystem:
    def __init__(self):
        self.personal_info = {}
        self.work_info = {}

    def get_personal_info(self):
        print("Enter Personal Information:")
        self.personal_info["Name"] = input("Name: ")
        self.personal_info["Age"] = int(input("Age: "))
        self.personal_info["Gender"] = input("Gender: ")
        self.personal_info["Address"] = input("Address: ")
        print('-'*25)

    def get_work_info(self):
        print("\nEnter Work Information:")
        self.work_info["Job Title"] = input("Job Title: ")
        self.work_info["Department"] = input("Department: ")
        print('-'*25)

    def input_performance_details(self):
        print("\nEnter Performance Evaluation Details:")

        weights = {}
        parameters = [
            "Job Knowledge and Skills",
            # "Quality of Work",
            # "Productivity and Efficiency",
            # "Adaptability and Flexibility",
            # "Professional Development",
            # "Goal Achievement",
            # "Self-Assessment",
        ]
        for factor in parameters:
            weight = float(input(f"Enter weight for {factor} (0-1): "))
            weights[factor] = weight

            rating = float(input(f"Rate {factor} (1-5): "))
            self.work_info[factor] = rating
        print('-'*25)

        total_weight = sum(weights.values())
        for factor, weight in weights.items():
            weights[factor] = weight / total_weight

        self.weights = weights
        print(weights)

    def display_employee_details(self):
        print("\nEmployee Details:")
        print("Personal Information:", self.personal_info)
        print("Work Information:", self.work_info)

    def evaluate_performance(self):
        overall_score = 0.0
        for factor, weight in self.weights.items():
            rating = self.work_info.get(factor, 0)
            print("factor-->",factor,"rating-->",rating, " weight-->",weight)
            overall_score += (rating / 5.0) * weight
        return overall_score


# Main Program
def main():
    print("Employee Information System\n")

    # Create an instance of the EmployeeInformationSystem class
    employee_system = EmployeeInformationSystem()

    # Get Personal Information
    employee_system.get_personal_info()

    # Get Work Information
    employee_system.get_work_info()

    # Input Performance Details
    employee_system.input_performance_details()

    # Evaluate Performance
    performance_score = employee_system.evaluate_performance()

    # Display the collected information and performance score
    employee_system.display_employee_details()
    print(f"\nOverall Performance Score: {performance_score:.2%}")


if __name__ == "__main__":
    main()




# Employee Information System

# Enter Personal Information:
# Name: John Doe
# Age: 35
# Gender: Male
# Address: 123 Main Street
# -------------------------

# Enter Work Information:
# Job Title: Software Engineer
# Department: Engineering
# -------------------------

# Enter Performance Evaluation Details:
# Enter weight for Job Knowledge and Skills (0-1): 0.4
# Rate Job Knowledge and Skills (1-5): 4



# Employee Details:
# Personal Information: {'Name': 'John Doe', 'Age': 35, 'Gender': 'Male', 'Address': '123 Main Street'}
# Work Information: {'Job Title': 'Software Engineer', 'Department': 'Engineering', 'Job Knowledge and Skills': 4.0}

# Overall Performance Score: 32.00%
