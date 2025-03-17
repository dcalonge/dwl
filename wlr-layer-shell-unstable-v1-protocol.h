/* Generated by wayland-scanner 1.23.0 */

#ifndef WLR_LAYER_SHELL_UNSTABLE_V1_ENUM_PROTOCOL_H
#define WLR_LAYER_SHELL_UNSTABLE_V1_ENUM_PROTOCOL_H

#ifdef  __cplusplus
extern "C" {
#endif

#ifndef ZWLR_LAYER_SHELL_V1_ERROR_ENUM
#define ZWLR_LAYER_SHELL_V1_ERROR_ENUM
enum zwlr_layer_shell_v1_error {
	/**
	 * wl_surface has another role
	 */
	ZWLR_LAYER_SHELL_V1_ERROR_ROLE = 0,
	/**
	 * layer value is invalid
	 */
	ZWLR_LAYER_SHELL_V1_ERROR_INVALID_LAYER = 1,
	/**
	 * wl_surface has a buffer attached or committed
	 */
	ZWLR_LAYER_SHELL_V1_ERROR_ALREADY_CONSTRUCTED = 2,
};
#endif /* ZWLR_LAYER_SHELL_V1_ERROR_ENUM */

#ifndef ZWLR_LAYER_SHELL_V1_LAYER_ENUM
#define ZWLR_LAYER_SHELL_V1_LAYER_ENUM
/**
 * @ingroup iface_zwlr_layer_shell_v1
 * available layers for surfaces
 *
 * These values indicate which layers a surface can be rendered in. They
 * are ordered by z depth, bottom-most first. Traditional shell surfaces
 * will typically be rendered between the bottom and top layers.
 * Fullscreen shell surfaces are typically rendered at the top layer.
 * Multiple surfaces can share a single layer, and ordering within a
 * single layer is undefined.
 */
enum zwlr_layer_shell_v1_layer {
	ZWLR_LAYER_SHELL_V1_LAYER_BACKGROUND = 0,
	ZWLR_LAYER_SHELL_V1_LAYER_BOTTOM = 1,
	ZWLR_LAYER_SHELL_V1_LAYER_TOP = 2,
	ZWLR_LAYER_SHELL_V1_LAYER_OVERLAY = 3,
};
#endif /* ZWLR_LAYER_SHELL_V1_LAYER_ENUM */

#ifndef ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ENUM
#define ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ENUM
/**
 * @ingroup iface_zwlr_layer_surface_v1
 * types of keyboard interaction possible for a layer shell surface
 *
 * Types of keyboard interaction possible for layer shell surfaces. The
 * rationale for this is twofold: (1) some applications are not interested
 * in keyboard events and not allowing them to be focused can improve the
 * desktop experience; (2) some applications will want to take exclusive
 * keyboard focus.
 */
enum zwlr_layer_surface_v1_keyboard_interactivity {
	/**
	 * no keyboard focus is possible
	 *
	 * This value indicates that this surface is not interested in
	 * keyboard events and the compositor should never assign it the
	 * keyboard focus.
	 *
	 * This is the default value, set for newly created layer shell
	 * surfaces.
	 *
	 * This is useful for e.g. desktop widgets that display information
	 * or only have interaction with non-keyboard input devices.
	 */
	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_NONE = 0,
	/**
	 * request exclusive keyboard focus
	 *
	 * Request exclusive keyboard focus if this surface is above the
	 * shell surface layer.
	 *
	 * For the top and overlay layers, the seat will always give
	 * exclusive keyboard focus to the top-most layer which has
	 * keyboard interactivity set to exclusive. If this layer contains
	 * multiple surfaces with keyboard interactivity set to exclusive,
	 * the compositor determines the one receiving keyboard events in
	 * an implementation- defined manner. In this case, no guarantee is
	 * made when this surface will receive keyboard focus (if ever).
	 *
	 * For the bottom and background layers, the compositor is allowed
	 * to use normal focus semantics.
	 *
	 * This setting is mainly intended for applications that need to
	 * ensure they receive all keyboard events, such as a lock screen
	 * or a password prompt.
	 */
	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_EXCLUSIVE = 1,
	/**
	 * request regular keyboard focus semantics
	 *
	 * This requests the compositor to allow this surface to be
	 * focused and unfocused by the user in an implementation-defined
	 * manner. The user should be able to unfocus this surface even
	 * regardless of the layer it is on.
	 *
	 * Typically, the compositor will want to use its normal mechanism
	 * to manage keyboard focus between layer shell surfaces with this
	 * setting and regular toplevels on the desktop layer (e.g. click
	 * to focus). Nevertheless, it is possible for a compositor to
	 * require a special interaction to focus or unfocus layer shell
	 * surfaces (e.g. requiring a click even if focus follows the mouse
	 * normally, or providing a keybinding to switch focus between
	 * layers).
	 *
	 * This setting is mainly intended for desktop shell components
	 * (e.g. panels) that allow keyboard interaction. Using this option
	 * can allow implementing a desktop shell that can be fully usable
	 * without the mouse.
	 * @since 4
	 */
	ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ON_DEMAND = 2,
};
/**
 * @ingroup iface_zwlr_layer_surface_v1
 */
#define ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ON_DEMAND_SINCE_VERSION 4
#endif /* ZWLR_LAYER_SURFACE_V1_KEYBOARD_INTERACTIVITY_ENUM */

#ifndef ZWLR_LAYER_SURFACE_V1_ERROR_ENUM
#define ZWLR_LAYER_SURFACE_V1_ERROR_ENUM
enum zwlr_layer_surface_v1_error {
	/**
	 * provided surface state is invalid
	 */
	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_SURFACE_STATE = 0,
	/**
	 * size is invalid
	 */
	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_SIZE = 1,
	/**
	 * anchor bitfield is invalid
	 */
	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_ANCHOR = 2,
	/**
	 * keyboard interactivity is invalid
	 */
	ZWLR_LAYER_SURFACE_V1_ERROR_INVALID_KEYBOARD_INTERACTIVITY = 3,
};
#endif /* ZWLR_LAYER_SURFACE_V1_ERROR_ENUM */

#ifndef ZWLR_LAYER_SURFACE_V1_ANCHOR_ENUM
#define ZWLR_LAYER_SURFACE_V1_ANCHOR_ENUM
enum zwlr_layer_surface_v1_anchor {
	/**
	 * the top edge of the anchor rectangle
	 */
	ZWLR_LAYER_SURFACE_V1_ANCHOR_TOP = 1,
	/**
	 * the bottom edge of the anchor rectangle
	 */
	ZWLR_LAYER_SURFACE_V1_ANCHOR_BOTTOM = 2,
	/**
	 * the left edge of the anchor rectangle
	 */
	ZWLR_LAYER_SURFACE_V1_ANCHOR_LEFT = 4,
	/**
	 * the right edge of the anchor rectangle
	 */
	ZWLR_LAYER_SURFACE_V1_ANCHOR_RIGHT = 8,
};
#endif /* ZWLR_LAYER_SURFACE_V1_ANCHOR_ENUM */

#ifdef  __cplusplus
}
#endif

#endif
