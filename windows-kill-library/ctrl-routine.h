#pragma once
namespace WindowsKillLibrary {
	/// <summary>
	/// Ctrl routine for finding and caching the address of specific event type.
	/// The address will be chached. So no need to do duplicate address finding.
	/// </summary>
	class CtrlRoutine {
	private:
		/// <summary>
		/// The event type of ctrl routine.
		/// </summary>
		DWORD event_type;

		/// <summary>
		/// The address of ctrl routine.
		/// </summary>
		LPTHREAD_START_ROUTINE address;

		/// <summary>
		/// The found address event.
		/// </summary>
		HANDLE found_address_event;

		static CtrlRoutine* current_routine;

		/// <summary>
		/// Gets the type of ctrl routine event.
		/// </summary>
		/// <returns>Ctrl Routine Event Type</returns>
		DWORD getEventType(void);

		/// <summary>
		/// Finds the address by stackbacktrace.
		/// </summary>
		void findAddressByStackBackTrace(void);

		/// <summary>
		/// Custom console ctrl handler.
		/// </summary>
		/// <param name="ctrl_type">Type of the ctrl event.</param>
		/// <returns></returns>
		static BOOL customConsoleCtrlHandler(DWORD ctrl_type);
	public:
		/// <summary>
		/// Initializes a new instance of the <see cref="CtrlRoutine" /> class.
		/// </summary>
		/// <param name="event_type">Type of the event.</param>
		CtrlRoutine(DWORD event_type);

		/// <summary>
		/// Find and set the address of ctrl routine.
		/// </summary>
		void findAddress();

		/// <summary>
		/// Gets the address of ctrl routine.
		/// </summary>
		/// <returns>Ctrl Routine Address</returns>
		LPTHREAD_START_ROUTINE getAddress(void);
	};
}
