// SPDX-License-Identifier: MIT
pragma solidity ^0.8.20;

contract StudentData {

    // Structure to store student details
    struct Student {
        uint256 rollNo;
        string name;
        string course;
        uint256 marks;
    }

    // Array to store students
    Student[] public students;

    // Mapping to check duplicate roll numbers
    mapping(uint256 => bool) public rollNoExists;

    // Event
    event StudentAdded(uint256 indexed rollNo, string name);

    // Add student
    function addStudent(
        uint256 _rollNo,
        string calldata _name,
        string calldata _course,
        uint256 _marks
    ) public {

        require(!rollNoExists[_rollNo], "Roll number already exists");
        require(bytes(_name).length > 0, "Name cannot be empty");
        require(bytes(_course).length > 0, "Course cannot be empty");
        require(_marks <= 100, "Marks must be between 0 and 100");

        students.push(Student(_rollNo, _name, _course, _marks));

        rollNoExists[_rollNo] = true;

        emit StudentAdded(_rollNo, _name);
    }

    // Get one student
    function getStudent(uint256 _index)
        public
        view
        returns (uint256, string memory, string memory, uint256)
    {
        require(_index < students.length, "Invalid index");

        Student storage student = students[_index];

        return (
            student.rollNo,
            student.name,
            student.course,
            student.marks
        );
    }

    // Get all students
    function getAllStudents() public view returns (Student[] memory) {
        return students;
    }

    // Get student count
    function getStudentCount() public view returns (uint256) {
        return students.length;
    }
}
