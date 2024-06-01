document.addEventListener('DOMContentLoaded', function() {
    // Function to handle form submission
    function handleSubmit(event) {
      event.preventDefault(); // Prevent default form submission behavior

      // Get the value entered by the user
      var nameInput = document.getElementById('name');
      var name = nameInput.value;

      // Display a greeting message with the user's name
      var greetingDiv = document.getElementById('greeting');
      greetingDiv.textContent = 'Hello, ' + name + '!';
    }

    // Add event listener to the form for form submission
    var nameForm = document.getElementById('nameForm');
    nameForm.addEventListener('submit', handleSubmit);
  });
