<?php
// Parent Class
class Lecturer {
    public $name;
    public $salary;

    // Constructor
    function __construct($name, $salary) {
        $this->name = $name;
        $this->salary = $salary;
    }

    // Method to display details (Can be overridden)
    function displayDetails() {
        echo "Name: $this->name <br>";
        echo "Salary: $this->salary <br>";
    }
}

// Child Class Parttime
class Parttime extends Lecturer {
    public $hoursWorked;

    // Constructor for Parttime (using parent constructor)
    function __construct($name, $salary, $hoursWorked) {
        parent::__construct($name, $salary);
        $this->hoursWorked = $hoursWorked;
    }
    // Overriding the displayDetails method (Polymorphism)
    function displayDetails() {
        echo "Parttime Lecturer: $this->name <br>";
        echo "Salary: $this->salary <br>";
        echo "Hours Worked: $this->hoursWorked <br><br>";
    }
}
// Child Class Fulltime
class Fulltime extends Lecturer {
    public $benefits;
    // Constructor for Fulltime (using parent constructor)
    function __construct($name, $salary, $benefits) {
        parent::__construct($name, $salary);
        $this->benefits = $benefits;
    }
    // Overriding the displayDetails method (Polymorphism)
    function displayDetails() {
        echo "Fulltime Lecturer: $this->name <br>";
        echo "Salary: $this->salary <br>";
        echo "Benefits: $this->benefits <br><br>";
    }
}
// Create objects for both Parttime and Fulltime
$parttimeLecturer = new Parttime("John", 3000, 20);  // 20 hours worked
$fulltimeLecturer = new Fulltime("Alice", 5000, "Health Insurance");
// Display details using polymorphism
$parttimeLecturer->displayDetails();
$fulltimeLecturer->displayDetails();
?>
