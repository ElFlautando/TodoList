#pragma once

enum class TodoStatus{
    None,
    Completed, 
    Urgent,
    Priority, //Not as important as urgent
    Sleeping, // Depending on other events, cannot work on it right now
    Optional, // Can be canceled
    Canceled, // Not needed anymore
};