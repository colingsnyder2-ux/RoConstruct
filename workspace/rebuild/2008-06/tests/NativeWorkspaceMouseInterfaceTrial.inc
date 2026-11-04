class MouseCommand {
public:
 virtual const Name& getName() const = 0;
 virtual MouseCommand* onMouseDown(const UIEvent&);
 virtual void onMouseIdle(const UIEvent&);
 virtual void onMouseHover(const UIEvent&);
 virtual MouseCommand* onKeyDown(const UIEvent&);
 virtual MouseCommand* onPeekKeyDown(const UIEvent&);
 virtual void onMouseMove(const UIEvent&);
 virtual void onMouseDelta(const UIEvent&);
 virtual MouseCommand* onMouseUp(const UIEvent&);
 virtual void capture();
 virtual void releaseCapture();
 virtual void cancel();
 virtual ~MouseCommand();
};
