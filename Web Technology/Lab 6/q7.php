<?php
// Parent Class
class Lecturer {
    public $name;
    protected $salary;
    private $department;

    function __construct($name, $salary, $department) {
        $this->name = $name;
        $this->salary = $salary;
        $this->department = $department;
    }

    public function getSalary() { return $this->salary; }
}

// Child Class Parttime
class Parttime extends Lecturer {
    public $hoursWorked;
    function __construct($name, $salary, $department, $hoursWorked) {
        parent::__construct($name, $salary, $department);
        $this->hoursWorked = $hoursWorked;
    }
    function display() {
        echo "Parttime: $this->name, Salary: {$this->getSalary()} <br>"; // Corrected here
    }
}

// Child Class Fulltime
class Fulltime extends Lecturer {
    public $benefits;
    function __construct($name, $salary, $department, $benefits) {
        parent::__construct($name, $salary, $department);
        $this->benefits = $benefits;
    }
    function display() {
        echo "Fulltime: $this->name, Benefits: $this->benefits <br>";
    }
}

// Objects
$parttime = new Parttime("John", 3000, "Math", 20);
$fulltime = new Fulltime("Alice", 5000, "CS", "Health Insurance");

$parttime->display();
$fulltime->display();
?>
