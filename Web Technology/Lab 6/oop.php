<?php
class Student {
    public $name;
    // Constructor
    function __construct($name) {
        $this->name = $name;
        echo "Created: $this->name<br>";
    }
    // Destructor
    function __destruct() {
        echo "Destroyed: $this->name<br>";
    }
}
// Create object
$student1 = new Student("Ram");
$student2 = new Student("Shyam");
?>
