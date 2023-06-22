class Process:
    def _init_(self, pid, burst_time, priority):
        self.pid = pid
        self.burst_time = burst_time
        self.priority = priority

def priority_scheduling(processes):
    n = len(processes)

    # Sort the processes based on priority (ascending order)
    processes.sort(key=lambda x: x.priority)

    # Initialize waiting time, turnaround time, and total waiting time
    waiting_time = [0] * n
    turnaround_time = [0] * n
    total_waiting_time = 0

    # Calculate waiting time for each process
    for i in range(1, n):
        waiting_time[i] = processes[i - 1].burst_time + waiting_time[i - 1]
        total_waiting_time += waiting_time[i]

    # Calculate turnaround time for each process
    for i in range(n):
        turnaround_time[i] = processes[i].burst_time + waiting_time[i]

    # Calculate average waiting time and average turnaround time
    average_waiting_time = total_waiting_time / n
    average_turnaround_time = sum(turnaround_time) / n

    # Print the process details and results
    print("Process ID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time")
    for i in range(n):
        p = processes[i]
        print(f"{p.pid}\t\t{p.burst_time}\t\t{p.priority}\t\t{waiting_time[i]}\t\t{turnaround_time[i]}")
    
    print(f"\nAverage Waiting Time: {average_waiting_time}")
    print(f"Average Turnaround Time: {average_turnaround_time}")

# Example usage
if _name_ == '_main_':
    # Create some sample processes
    processes = [
        Process(1, 6, 2),
        Process(2, 8, 1),
        Process(3, 3, 4),
        Process(4, 7, 3),
        Process(5, 4, 5)
    ]

    # Apply priority scheduling
    priority_scheduling(processes)
